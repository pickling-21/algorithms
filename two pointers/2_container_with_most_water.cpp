/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49. Example 2:

Input: height = [1,1]
Output: 1
*/

#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
  int f = 0;
  int s = height.size() - 1;

  int ans = 0;
  while (f < s) {
    int area = s - f;
    int curr = std::min(height[s], height[f]) * area;
    ans = std::max(curr, ans);

    if (height[f] < height[s]) {
      f++;
    } else {
      s--;
    }
  }
  return ans;
}

int main(void) {
  int n = 0;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  std::cout << maxArea(nums) << std::endl;
}

/*
9
1 8 6 2 5 4 8 3 7
*/