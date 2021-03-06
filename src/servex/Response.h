// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_RESPONSE_H
#define SERVEX_RESPONSE_H

#include <ostream>
#include "Headers.h"

namespace servex
{
    class Response
    {
    public:
        int GetStatus() const;

        Headers &GetHeaders();

        std::ostream &GetBody();

        void SetStatus(int status);

    private:
        int status = 200;
        std::ostream* body;
        Headers headers;
    };
}

#endif //SERVEX_RESPONSE_H
