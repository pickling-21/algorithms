/*
Leetcode

Given an integer array nums, move all 0's to the end of it while maintaining the
relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


Follow up: Could you minimize the total number of operations done?*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
  int i = 0;
  int j = nums.size() - 1;
  while () }

int main(void) {
  int n = 0;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  moveZeroes(nums);
  for (auto num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}