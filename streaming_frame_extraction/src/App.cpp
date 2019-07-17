#include "Common.hpp"
#include "AppComponent.hpp"

#include <memory>

/**** README ***** 
  HttpRouter - Router of HTTP requests. It maps URLs to endpoint handlers. 

  HttpConnectionHandler - This is a simple HTTP connection handler. 
  It handles incoming connections in a multi threaded manner, creating one thread per each connection.

  SimpleTCPConnectionProvider - Provider of TCP connections. It binds to a specified port.

  Server - Server runs a loop which takes connections from ConnectionProvider and passes them to ConnectionHandler.
  */

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)
class MessageDto : public oatpp::data::mapping::type::Object
{
  DTO_INIT(MessageDto, Object)
  DTO_FIELD(Int32, statusCode);
  DTO_FIELD(String, message);
};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

class Handler : public oatpp::web::server::HttpRequestHandler 
{
  public:
    OutgoingResponsePtr handle(const IncomingRequestPtr& request) override
    {
      auto message = MessageDto::createShared();
      message->statusCode = 1024;
      message->message = "Hello DTO!";

      return ResponseFactory::createResponse(Status::CODE_200, message, m_objectMapper.get());
    }

  private:
    OATPP_COMPONENT(ObjectMapperPtr, m_objectMapper);
};

void run()
{
  AppComponent component;

  // Create router for HTTP requests routing */
  OATPP_COMPONENT(HttpRouterPtr, router);

  router->route("GET", "/hello", std::make_shared<Handler>());

  // Create HTTP connection handler with router
  OATPP_COMPONENT(ConnectionHandlerPtr, connectionHandler);

  // Create TCP connection provider
  // Listens to incoming requests on specified port
  OATPP_COMPONENT(ServerConnectionProviderPtr, connectionProvider);

  // Pass TCP connections from provider to HTTP connection handler
  oatpp::network::server::Server server(connectionProvider, connectionHandler);

  OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

  server.run();
}

int main(int argc, char **argv)
{
  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;
}
