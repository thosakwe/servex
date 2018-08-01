// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "HttpDriverException.h"

servex::HttpDriverException::HttpDriverException(int errorCode, std::string &message) : errorCode(errorCode),
                                                                                        message(message) {
}

const char *servex::HttpDriverException::what() const noexcept {
    return message.c_str();
}

const std::string &servex::HttpDriverException::GetMessage() const {
    return message;
}

const int servex::HttpDriverException::GetErrno() const {
    return errorCode;
}
