// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPREQUEST_H
#define SERVEX_HTTPREQUEST_H

#include "../Request.h"
#include "HttpDriver.h"

namespace servex
{
    class HttpRequest : public Request
    {
    public:
        explicit HttpRequest(const HttpDriver::ClientInfo &info);

    private:
        const HttpDriver::ClientInfo &info;
    };
}

#endif //SERVEX_HTTPREQUEST_H
