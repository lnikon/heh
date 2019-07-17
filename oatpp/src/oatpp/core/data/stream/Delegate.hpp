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

#ifndef oatpp_data_stream_Delegate_hpp
#define oatpp_data_stream_Delegate_hpp

#include "./Stream.hpp"

namespace oatpp { namespace data{ namespace stream {

/**
 * Stream writer delegate which can write data to stream provided.
 */
class WriterDelegate {
public:

  /**
   * Write data to provided stream.
   * @param stream - stream to write data to.
   * @return - actual number of bytes written to stream. &id:oatpp::data::v_io_size;.
   */
  virtual data::v_io_size writeToStream(const std::shared_ptr<OutputStream>& stream) = 0;
};

/**
 * Stream reader delegate which can read data from stream provided.
 */
class ReaderDelegate {
public:
  /**
   * Read data from provided stream.
   * @param stream - stream to read data from.
   * @return - actual number of bytes read. &id:oatpp::data::v_io_size;.
   */
  virtual data::v_io_size readFromStream(const std::shared_ptr<InputStream>& stream) = 0;
};
  
}}}

#endif /* oatpp_data_stream_Delegate_hpp */
