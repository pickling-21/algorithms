#include <iostream>
int permutations(int n) {
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}
int repetitions(int n, int k) {
  int fn = permutations(n + k - 1);
  int fk = permutations(k);
  int fsub = permutations(n - 1);
  return fn / (fsub * fk);
}

int main(void) {
  int n, k;
  std::cin >> n >> k;
  std::cout << repetitions(n, k);

  std::cout << std::endl;
}