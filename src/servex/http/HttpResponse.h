// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPRESPONSE_H
#define SERVEX_HTTPRESPONSE_H

#include "../Request.h"
#include "HttpDriver.h"

namespace servex
{
    class HttpResponse : public Response
    {
    public:
        explicit HttpResponse(const HttpDriver::ClientInfo &info);

    private:
        const HttpDriver::ClientInfo &info;
    };
}

#endif //SERVEX_HTTPRESPONSE_H
