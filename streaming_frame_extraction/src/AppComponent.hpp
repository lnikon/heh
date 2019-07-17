#pragma once

#include "Common.hpp"
#include "Config.hpp"

#include "oatpp/core/macro/component.hpp"

class AppComponent 
{
  public:
    // Provider of TCP connections. It listens on a specified port.
    OATPP_CREATE_COMPONENT(ServerConnectionProviderPtr, serverConnectionProvider)
      ([] {
       return oatpp::network::server::SimpleTCPConnectionProvider::createShared(PORT_TO_LISTEN);
       }());

    // HTTP request router
    OATPP_CREATE_COMPONENT(HttpRouterPtr, httpRouter)
      ([] {
       return oatpp::web::server::HttpRouter::createShared();
       }());

    // ConnectionHandler uses router to route components
    OATPP_CREATE_COMPONENT(ConnectionHandlerPtr, serverConnectionHandler)
      ([] {
       // Get router component
       OATPP_COMPONENT(HttpRouterPtr, router);
       return oatpp::web::server::HttpConnectionHandler::createShared(router);
       }());

    // Don't forget about serialization
    OATPP_CREATE_COMPONENT(ObjectMapperPtr, apiObjectMapper)
      ([] {
       return oatpp::parser::json::mapping::ObjectMapper::createShared();
       }());

};
