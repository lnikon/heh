#pragma once

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/server/Server.hpp"
#include "oatpp/network/server/SimpleTCPConnectionProvider.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

using ServerConnectionProviderPtr = std::shared_ptr<oatpp::network::ServerConnectionProvider>;

using HttpRouterPtr = std::shared_ptr<oatpp::web::server::HttpRouter>;

using ConnectionHandlerPtr = std::shared_ptr<oatpp::network::server::ConnectionHandler>;

using IncomingRequestPtr = std::shared_ptr<oatpp::web::server::HttpRequestHandler::IncomingRequest>;

using OutgoingResponsePtr = std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse>;

using ObjectMapperPtr = std::shared_ptr<oatpp::data::mapping::ObjectMapper>;

