#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

int nsd(std::vector<int> vec) {}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }
}