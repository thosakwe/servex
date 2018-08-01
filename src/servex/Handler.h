// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HANDLER_H
#define SERVEX_HANDLER_H

#include "Request.h"
#include "Response.h"

namespace servex
{
    class Handler
    {
        virtual bool CanAccept(const Request &request) const = 0;

        virtual void Handle(const Request &request, Response &response) = 0;
    };
}

#endif //SERVEX_HANDLER_H
