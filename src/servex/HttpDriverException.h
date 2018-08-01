// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPDRIVEREXCEPTION_H
#define SERVEX_HTTPDRIVEREXCEPTION_H

#include <stdexcept>
#include <string>

namespace servex
{
    class HttpDriverException : public std::exception
    {
    public:
        explicit HttpDriverException(int errorCode, std::string &message);

        const char *what() const override;

        const std::string &GetMessage() const;

        const int GetErrno() const;

    private:
        const int errorCode;
        std::string &message;
    };
}

#endif //SERVEX_HTTPDRIVEREXCEPTION_H
