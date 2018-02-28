//
// Created by wcj on 12/1/17.
//

#ifndef LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
#define LEETCODE_11_CONTAINER_WITH_MOST_WATER_H

//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include <vector>

namespace leetcode {
class ContainerWithMostWater {
 public:
  static int maxArea1(std::vector<int> &height) {
    if (height.size() < 2) return -1;
    int max = 0;
    for (int i = 1; i < height.size(); ++i) {
      for (int j = 0; j < i; j++) {
        int area = (i - j) * std::min(height[i], height[j]);
        if (area > max)
          max = area;
      }
    }
    return max;
  }

  // Avoid repeated search
  static int maxArea2(std::vector<int> &height) {
    if (height.size() < 2) return -1;
    int max = 0;
    int lidx = 0, ridx = (int) height.size() - 1;
    while (lidx < ridx) {
      int area = (ridx - lidx) * std::min(height[lidx], height[ridx]);
      if (area > max) max = area;
      if (height[lidx] < height[ridx]) lidx++;
      else ridx--;
    }
    return max;
  }
};
}

#endif //LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
