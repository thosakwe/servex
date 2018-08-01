// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPEXCEPTION_H
#define SERVEX_HTTPEXCEPTION_H

#include <stdexcept>

namespace servex
{
    class HttpException : public std::exception
    {

    };
}

#endif //SERVEX_HTTPEXCEPTION_H
