#ifndef PROTON_CPP_BLOCKING_CONNECTION_IMPL_H
#define PROTON_CPP_BLOCKING_CONNECTION_IMPL_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#include "proton/export.hpp"
#include "proton/container.hpp"
#include "proton/messaging_handler.hpp"
#include "proton/connection.hpp"
#include "proton/types.h"
#include <string>

struct pn_connection_t;

namespace proton {

class handler;
class container;

class blocking_connection_impl : public messaging_handler
{
  public:
    blocking_connection_impl(const url &url, duration d);
    ~blocking_connection_impl();

    void close();

    struct condition {
        virtual ~condition() {}
        virtual bool operator()() const = 0;
    };

    void wait(const condition&, const std::string & ="", duration=duration(-1));

    PN_UNIQUE_PTR<container> container_;
    counted_ptr<connection> connection_;
};


}

#endif  /*!PROTON_CPP_BLOCKING_CONNECTION_IMPL_H*/