//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_140_THE_SAMPLE_STRUCTURE_HPP
#define LEETCODE_140_THE_SAMPLE_STRUCTURE_HPP

#include <memory>
#include <node.hpp>

namespace interview {

class TheSameStruct {
public:
    static bool contains(const std::shared_ptr<Node>& t1, const std::shared_ptr<Node>& t2) {
        if (t2 == nullptr) return true;
        if (t1 == nullptr) return false;
        return check(t1, t2) || contains(t1->left, t2) || contains(t1->right, t2);
    }

private:
    static bool check(const std::shared_ptr<Node>& h, const std::shared_ptr<Node>& t2) {
        if (t2 == nullptr) return true;
        if (h == nullptr || h->value != t2->value) return false;
        return check(h->left, t2->left) && check(h->right, t2->right);
    }

};

}

#endif //LEETCODE_140_THE_SAMPLE_STRUCTURE_HPP
