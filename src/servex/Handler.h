// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HANDLER_H
#define SERVEX_HANDLER_H

#include "Driver.h"
#include "Request.h"
#include "Response.h"

namespace servex
{
    class Handler
    {
    public:
        virtual bool CanAccept(const Client &client) const = 0;

        virtual void Handle(const Request &request, Response &response) const = 0;

        /**
         * Transforms an accepted client into another representation of incoming data.
         *
         * Allows you to "wrap" functionality, i.e. for compression, etc.
         * @param client
         * @return Returns a new request and response, OR the current values.
         */
        virtual Client *Transform(Client *client) const;
    };
}

#endif //SERVEX_HANDLER_H
