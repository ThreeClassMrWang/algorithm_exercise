//
// Created by wcj on 17-12-1.
//

#ifndef LEETCODE_15_3SUM_H
#define LEETCODE_15_3SUM_H

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

#include <vector>
#include <unordered_set>
#include <algorithm>

namespace leetcode {
    class ThreeSum {
    public:
        static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::vector<std::vector<int>> threeRes;
            if (nums.size() < 3) return threeRes;
            for (std::size_t i = 0; i < nums.size() - 1; ++i) {
                std::vector<std::vector<int>> twoRes;
                TwoSum(nums, i + 1, -nums[i], twoRes);
                for (int j = 0; j < twoRes.size(); ++j) {
                    std::vector<int> res{twoRes[j][0], twoRes[j][1], nums[i]};
                    std::sort(res.begin(), res.end());
                    threeRes.push_back(res);
                }
            }
            std::sort(threeRes.begin(), threeRes.end(),
                      [](const std::vector<int> &a, const std::vector<int> &b) {
                          return (a[0] < b[0]) ||
                                 (a[0] == b[0] && a[1] < b[1]);
                      });
            auto end = std::unique(threeRes.begin(), threeRes.end(),
                                   [](const std::vector<int> &a, const std::vector<int> &b) {
                                       return (a[0] == b[0] && a[1] == b[1]);
                                   });
            return std::vector<std::vector<int>>(threeRes.begin(), end);
        }

        static std::vector<std::vector<int>> threeSum2(std::vector<int>& nums) {
            std::vector<std::vector<int>> threeRes;
            if (nums.size() < 3) return threeRes;
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; ++i) {
                if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                    int lo = i + 1, hi = (int)nums.size() - 1, sum = -nums[i];
                    while (lo < hi) {
                        if (nums[lo] + nums[hi] == sum) {
                            threeRes.emplace_back(std::vector<int>{nums[i], nums[lo], nums[hi]});
                            while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                            while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                            lo++; hi--;
                        } else if (nums[lo] + nums[hi] < sum) {
                            lo++;
                        } else {
                            hi--;
                        }
                    }
                }
            }
            return threeRes;
        }

    private:

        static void TwoSum(std::vector<int>& nums, std::size_t startIdx, int x, std::vector<std::vector<int>>& res) {
            std::unordered_set<int> set;
            for (std::size_t i = startIdx; i < nums.size(); ++i) {
                int target = x - nums[i];
                if (set.find(target) !=  set.end()) {
                    // Found
                    std::vector<int> singleRes{std::min(nums[i], target), std::max(nums[i], target)};
                    res.push_back(singleRes);
                } else {
                    set.insert(nums[i]);
                }
            }
        }
};
}

#endif //LEETCODE_15_3SUM_H
