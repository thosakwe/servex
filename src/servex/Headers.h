// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HEADERS_H
#define SERVEX_HEADERS_H

#include <string>
#include <unordered_map>
#include <vector>

namespace servex
{
    class Headers
    {
        Headers();

        Headers(const Headers &other);

        Headers(const Headers &&other) noexcept;

        bool Contains(const std::string &name) const;

        const std::vector<std::string> &Get(const std::string &name) const;

       std::vector<std::string> &GetMutable(const std::string &name);

        std::string Join(const std::string &name) const;

        void Add(const std::string &name, const std::string &value);

        void Overwrite(const std::string &name, const std::string &value);

        void Clear();

    private:
        std::unordered_map<std::string, std::vector<std::string>> headers;
    };
}

#endif //SERVEX_HEADERS_H
