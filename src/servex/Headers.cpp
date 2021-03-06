// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "Headers.h"

servex::Headers::Headers() = default;

servex::Headers::Headers(const servex::Headers &other) {
    if (this != &other) {
        headers.insert(other.headers.begin(), other.headers.end());
    }
}

servex::Headers::Headers(servex::Headers &&other) noexcept {
    if (this != &other) {
        headers.insert(other.headers.begin(), other.headers.end());
    }

    other.headers.clear();
}

bool servex::Headers::Contains(const std::string &name) const {
    return headers.find(name) != headers.end();
}

const std::vector<std::string> &servex::Headers::Get(const std::string &name) const {
    if (Contains(name)) {
        return headers.at(name);
    } else {
        std::vector<std::string> emptyVector;
        return std::move(emptyVector);
    }
}

const std::vector<std::string> servex::Headers::GetKeys() const {
    std::vector<std::string> keys;

    for (auto &pair : headers) {
        keys.push_back(pair.first);
    }

    return keys;
}

std::vector<std::string> &servex::Headers::GetMutable(const std::string &name) {
    if (Contains(name)) {
        return headers.at(name);
    } else {
        std::vector<std::string> emptyVector;
        headers.insert(std::make_pair(name, emptyVector));
        return GetMutable(name);
    }
}

std::string servex::Headers::Join(const std::string &name) const {
    std::ostringstream oss;

    unsigned long i = 0;

    for (auto &value : Get(name)) {
        if (i++ > 0) oss << ",";
        oss << name;
    }

    return oss.str();
}

void servex::Headers::Add(const std::string &name, const std::string &value) {
    GetMutable(name).push_back(value);
}

void servex::Headers::Overwrite(const std::string &name, const std::string &value) {
    auto &values = GetMutable(name);
    values.clear();
    values.push_back(value);
}

void servex::Headers::Clear() {
    headers.clear();
}
