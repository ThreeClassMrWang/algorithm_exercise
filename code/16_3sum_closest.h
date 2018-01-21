//
// Created by wcj on 17-12-1.
//

#ifndef LEETCODE_16_3SUM_CLOSEST_H
#define LEETCODE_16_3SUM_CLOSEST_H

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <vector>
#include <algorithm>

namespace leetcode {
    class ThreeSumCloset {
    public:
        static int threeSumClosest(std::vector<int>& nums, int target) {
            int closet = INT32_MAX;
            int closetValue = INT32_MAX;
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; ++i) {
                int lo = i + 1, hi = (int)nums.size() - 1, sum = target - nums[i];
                int dist = INT32_MAX;
                int distValue = INT32_MAX;
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        return target;
                    } else if (nums[lo] + nums[hi] < sum) {
                        int diff = std::abs(nums[lo] + nums[hi] - sum);
                        if ( diff < dist) {
                            dist = diff;
                            distValue = nums[lo] + nums[hi] + nums[i];
                        }
                        lo++;
                    } else {
                        int diff = std::abs(nums[lo] + nums[hi] - sum);
                        if ( diff < dist){
                            dist = diff;
                            distValue = nums[lo] + nums[hi] + nums[i];
                        }
                        hi--;
                    }
                }
                if (dist < closet) {
                    closet = dist;
                    closetValue = distValue;
                }
            }

            return closetValue;
        }
    };
}

#endif //LEETCODE_16_3SUM_CLOSEST_H
