/*
1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and
remove them from the array.

Return the maximum number of operations you can perform on the array.



Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

#include <iostream>
#include <unordered_map>
#include <vector>

void print_map(const std::unordered_map<int, int>& seen) {
  for (auto p : seen) {
    std::cout << p.first << " " << p.second << std::endl;
  }
}
int maxOperations(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> seen;
  int count = 0;
  for (int num : nums) {
    seen[num]++;
  }
  for (int num : nums) {
    int target = k - num;
    if (seen[target] > 0) {
      seen[num]--;
      seen[target]--;
      count++;
    }
    print_map(seen);
    std::cout << "------\n";
  }
  return count;
}

int main(void) {
  int n = 0;
  int k = 0;
  std::cin >> k;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  std::cout << maxOperations(nums, k) << std::endl;
}
