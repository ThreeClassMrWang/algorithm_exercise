//
// Created by wcj on 17-11-14.
//

#ifndef LEETCODE_9_PALINDROME_NUMBER_H
#define LEETCODE_9_PALINDROME_NUMBER_H

//Determine whether an integer is a palindrome. Do this without extra space.

#include "7_reverse_integer.h"

namespace leetcode {
    class PalindromeNumber {
        bool isPalindrome(int x) {
            if (x < 0)
                return false;
            else
                return x == leetcode::ReverseInterger::reverse(x);
        }
    };
}

#endif //LEETCODE_9_PALINDROME_NUMBER_H
