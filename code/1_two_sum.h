//
// Created by wcj on 17-11-14.
//

#ifndef LEETCODE_1_TWO_SUM_H
#define LEETCODE_1_TWO_SUM_H

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//        Given nums = [2, 7, 11, 15], target = 9,
//
//        Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

#include <vector>
#include <exception>
#include <stdexcept>
#include <map>
#include <unordered_map>

namespace leetcode {
    class TwoSum {
    public:
        std::vector<int> twoSum_1(std::vector<int> &nums, int targets) {
            for (std::size_t i = 0; i < nums.size(); ++i)
                for (std::size_t j = i + 1; j < nums.size(); ++j) {
                    if (nums[i] + nums[j] == targets)
                        return std::vector<int>{i, j};
                }

            throw std::runtime_error("No two sum solution");
        }

        std::vector<int> twoSum_2(std::vector<int> &nums, int targets) {
            std::map<int, std::size_t> m;
            std::map<int, std::size_t>::iterator it;
            for (std::size_t i = 0; i < nums.size(); ++i) {
                int remains = targets - nums[i];
                if ((it = m.find(remains)) != m.end())
                    return std::vector<int>{it->second, i};
                m[nums[i]] = i;
            }

            throw std::runtime_error("No two sum solution");
        }

        std::vector<int> twoSum_3(std::vector<int> &nums, int targets) {
            std::unordered_map<int, std::size_t> m;
            std::unordered_map<int, std::size_t>::iterator it;
            for (std::size_t i = 0; i < nums.size(); ++i) {
                int remains = targets - nums[i];
                if ((it = m.find(remains)) != m.end())
                    return std::vector<int>{it->second, i};
                m[nums[i]] = i;
            }

            throw std::runtime_error("No two sum solution");
        }
    };
}

#endif //LEETCODE_1_TWO_SUM_H
