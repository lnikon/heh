/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_web_protocol_http_outgoing_Request_hpp
#define oatpp_web_protocol_http_outgoing_Request_hpp

#include "oatpp/web/protocol/http/outgoing/Body.hpp"
#include "oatpp/web/protocol/http/Http.hpp"

namespace oatpp { namespace web { namespace protocol { namespace http { namespace outgoing {

/**
 * Class http::outgoing::Request AKA OutgoingRequest represents client's outgoing request to server.
 */
class Request : public oatpp::base::Countable, public std::enable_shared_from_this<Request> {
public:
  /**
   * Convenience typedef for &id:oatpp::web::protocol::http::Headers;.
   */
  typedef protocol::http::Headers Headers;
public:
  OBJECT_POOL(Outgoing_Request_Pool, Request, 32)
  SHARED_OBJECT_POOL(Shared_Outgoing_Request_Pool, Request, 32)
private:
  oatpp::data::share::StringKeyLabel m_method;
  oatpp::data::share::StringKeyLabel m_path;
  Headers m_headers;
  std::shared_ptr<Body> m_body;
public:

  /**
   * Constructor.
   * @param method - http method. &id:oatpp::data::share::StringKeyLabel;.
   * @param path - path to resource. &id:oatpp::data::share::StringKeyLabel;.
   * @param headers - &l:Request::Headers;.
   * @param body - `std::shared_ptr` to &id:oatpp::web::protocol::http::outgoing::Body;.
   */
  Request(const oatpp::data::share::StringKeyLabel& method,
          const oatpp::data::share::StringKeyLabel& path,
          const Headers& headers,
          const std::shared_ptr<Body>& body);
  
public:

  /**
   * Create shared Request.
   * @param method - http method. &id:oatpp::data::share::StringKeyLabel;.
   * @param path - path to resource. &id:oatpp::data::share::StringKeyLabel;.
   * @param headers - &l:Request::Headers;.
   * @param body - `std::shared_ptr` to &id:oatpp::web::protocol::http::outgoing::Body;.
   * @return - `std::shared_ptr` to Request.
   */
  static std::shared_ptr<Request> createShared(const oatpp::data::share::StringKeyLabel& method,
                                               const oatpp::data::share::StringKeyLabel& path,
                                               const Headers& headers,
                                               const std::shared_ptr<Body>& body);

  /**
   * Get http method.
   * @return - http method. &id:oatpp::data::share::StringKeyLabel;.
   */
  const oatpp::data::share::StringKeyLabel& getMethod() const;

  /**
   * Get path to resource.
   * @return - path to resource. &id:oatpp::data::share::StringKeyLabel;.
   */
  const oatpp::data::share::StringKeyLabel& getPath() const;

  /**
   * Get headers map.
   * @return - &l:Request::Headers;.
   */
  Headers& getHeaders();

  /**
   * Put http header to headers map.
   * @param key - header name &id:oatpp::data::share::StringKeyLabelCI_FAST;.
   * @param value - header value &id:oatpp::data::share::StringKeyLabel;.
   */
  void putHeader(const oatpp::data::share::StringKeyLabelCI_FAST& key, const oatpp::data::share::StringKeyLabel& value);

  /**
   * Put http header to headers map if no header with such name exists.
   * Leave old "name: value" in case such header exists.
   * @param key - header name &id:oatpp::data::share::StringKeyLabelCI_FAST;.
   * @param value - header value &id:oatpp::data::share::StringKeyLabel;.
   * @return - `true` if header was added to the map.
   */
  bool putHeaderIfNotExists(const oatpp::data::share::StringKeyLabelCI_FAST& key, const oatpp::data::share::StringKeyLabel& value);

  /**
   * Get http body.
   * @return - &id:oatpp::web::protocol::http::outgoing::Body;.
   */
  std::shared_ptr<Body> getBody();

  /**
   * Write request to stream.
   * @param stream - &id:oatpp::data::stream::OutputStream;.
   */
  void send(const std::shared_ptr<data::stream::OutputStream>& stream);

  /**
   * Write request to stream in asynchronous manner.
   * @param stream - &id:oatpp::data::stream::OutputStream;.
   * @return - &id:oatpp::async::CoroutineStarter;.
   */
  oatpp::async::CoroutineStarter sendAsync(const std::shared_ptr<data::stream::OutputStream>& stream);
  
};
  
}}}}}

#endif /* oatpp_web_protocol_http_outgoing_Request_hpp */
