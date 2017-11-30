//
// Created by wcj on 17-11-30.
//

#ifndef LEETCODE_8_STRING_TO_INTEGER_H
#define LEETCODE_8_STRING_TO_INTEGER_H

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//
//spoilers alert... click to show requirements for atoi.
//
//Requirements for atoi:
//        The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <string>

namespace leetcode {
    class StringToInteger {
    public:
        static int myAtoi(const std::string &str) {
            bool start = false;
            long long value = 0;
            int flag = 1;
            for (size_t i = 0; i < str.length(); ++i) {

                if (!start && (str[i] == '+' || str[i] == '-')) {
                    if (i + 1 < str.length() && !isIntegerChar(str[i+1]))
                        return 0;
                }

                if (!start && isIntegerChar(str[i])) {
                    start = true;
                    value = str[i] - '0';
                    if (i > 0 && str[i-1] == '-')
                        flag = -1;
                } else if (start && isIntegerChar(str[i])) {
                    value = 10 * value + str[i] - '0';
                    if (value * flag > INT32_MAX)
                        return 0;
                    else if (value * flag < INT32_MIN)
                        return INT32_MIN;
                }

                if (start && !isIntegerChar(str[i])) {
                    break;
                }

                if (!start && !isIntegerChar(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != ' ')
                    return 0;
            }
            return (int)(flag * value);
        }

    private:
        static bool isIntegerChar(const char c) {
            return (c >= '0' && c <= '9');
        }
    };
}

#endif //LEETCODE_8_STRING_TO_INTEGER_H
