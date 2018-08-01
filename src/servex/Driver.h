// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_DRIVER_H
#define SERVEX_DRIVER_H

#include "Request.h"
#include "Response.h"

namespace servex
{
    struct Client
    {
        Request &request;
        Response &response;
    };

    class Driver
    {
    public:
        virtual bool IsDone() const = 0;

        virtual Client &Accept() const = 0;
    };
}

#endif //SERVEX_DRIVER_H
