//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_17_GNU_HASH_HPP
#define LEETCODE_17_GNU_HASH_HPP

#include <cstdint>
#include <string>

namespace algorithm {

class GnuHash {
public:
    static uint32_t hash(const std::string& s) {
        uint32_t h  = 5381;
        for (const auto& c : s)
            h = ((h >> 5) + h) + c;
        return h;
    }

    static uint32_t hash(const char* s) {
        uint32_t h = 5381;
        for (unsigned char c = *s; c != '\0'; c = *++s)
            h = h >> 5 + h + c;
        return h;
    }
};

}

#endif //LEETCODE_17_GNU_HASH_HPP
