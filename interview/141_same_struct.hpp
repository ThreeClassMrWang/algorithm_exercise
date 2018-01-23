//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_141_SAME_STRUCT_HPP
#define LEETCODE_141_SAME_STRUCT_HPP

/// 判断t1树中是否含有t2树拓扑完全相同的子树

/// 方法思路： 把树使用字符串序列化，然后利用kmp判断子串

#include "node.hpp"
#include <vector>
#include <string>

namespace interview {

class SameStruct {
public:
    static bool contains(const std::shared_ptr<Node>&t1, const std::shared_ptr<Node>& t2) {
        std::string t1Str;
        serielByPre(t1, t1Str);
        std::string t2Str;
        serielByPre(t2, t2Str);

        ssize_t idx = kmp(t1Str, t2Str);

        return (idx >= 0);
    }

private:
    /// Serial tree.
    ///
    /// \param node
    /// \return
    static void serielByPre(const std::shared_ptr<Node>& node, std::string& res) {
        if (node == nullptr) {
            res += "#!";
            return;
        }

        res += (std::to_string(node->value) + "!");
        serielByPre(node->left, res);
        serielByPre(node->right, res);
    }

    /// Next for KMP
    ///
    /// \param pattern
    /// \param next
    static void getNext(const std::string& pattern, std::vector<ssize_t>& next) {
        ssize_t q{1}, k{0};
        next[0] = 0;

        for (; q < pattern.size(); ++q) {
            while (k > 0 && pattern[k] != pattern[q])
                k = next[k - 1];
            if (pattern[k] == pattern[q]) ++k;
            next[q] = k;
        }
    }

    /// KMP algorithm: Check if pattern exist in txt
    ///
    /// \param txt
    /// \param pattern
    /// \return
    static ssize_t kmp(const std::string& txt, const std::string& pattern) {
        std::vector<ssize_t> next(pattern.size(), 0);
        getNext(pattern, next);

        ssize_t i{0}, N{(ssize_t)txt.size()};
        ssize_t k{0}, M{(ssize_t)pattern.size()};

        for (; i < N; ++i) {

            while (k > 0 && pattern[k] != txt[i])
                k = next[k-1];
            if (pattern[k] == txt[i]) k++;
            if (k == M) return i - M + 1;
        }
        return -1;
    }

};

}

#endif //LEETCODE_141_SAME_STRUCT_HPP
