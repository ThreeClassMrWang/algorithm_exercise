//
// Created by wcj on 17-11-16.
//

#ifndef LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

//Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
//Example:
//
//        Given nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//It doesn't matter what you leave beyond the new length.

#include <vector>

namespace leetcode {
class RemoveDuplicatesFromSortedArray {
 public:
  static int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty())
      return 0;

    int i = 0, j = 1;
    std::size_t len = nums.size();
    for (; j < len; ++j) {
      while (nums[j] == nums[j - 1] && j < len) ++j;
      if (j < len)
        nums[++i] = nums[j];
    }
    return (i + 1);
  }
};
}

#endif //LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
