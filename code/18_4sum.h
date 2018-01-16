//
// Created by wcj on 12/3/17.
//

#ifndef LEETCODE_18_4SUM_H
#define LEETCODE_18_4SUM_H

//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//

#include <vector>
#include <algorithm>

namespace leetcode {
    class FourSum {
    public:
        static std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
            std::vector<std::vector<int>> fourRes;
            if (nums.size() < 4)
                return fourRes;
            std::sort(nums.begin(), nums.end());
            for (std::size_t i = 0; i < nums.size() - 3; ++i) {
                if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                    for (std::size_t j = i + 1; j < nums.size() - 2; ++j) {
                        if (j == i + 1 || (j > i + 1 &&  nums[j] != nums[j-1])) {
                            std::size_t lo = j + 1, hi = nums.size() - 1;
                            int sum = target - nums[i] - nums[j];
                            while (lo < hi) {
                                if (nums[lo] + nums[hi] == sum) {
                                    fourRes.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                                    while (nums[lo + 1] == nums[lo] && lo < hi) lo++;
                                    while (nums[hi - 1] == nums[hi] && lo < hi) hi--;
                                    lo++;
                                    hi--;
                                } else if (nums[lo] + nums[hi] < sum) {
                                    lo++;
                                } else {
                                    hi--;
                                }
                            }
                        }
                    }
                }
            }
            return std::move(fourRes);
        }
    };
}

#endif //LEETCODE_18_4SUM_H
