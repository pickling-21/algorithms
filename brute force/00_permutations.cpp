#include <iostream>

int permutations(int n) {
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}

int main(void) {
  int n;
  std::cin >> n;
  std::cout << permutations(n);

  std::cout << std::endl;
}