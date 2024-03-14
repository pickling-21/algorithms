#include <iostream>
int permutations(int n) {
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}
int combinations(int n, int k) {
  int fn = permutations(n);
  int fk = permutations(k);
  int fsub = permutations(n - k);
  return fn / (fsub * fk);
}

int main(void) {
  int n, k;
  std::cin >> n >> k;
  std::cout << combinations(n, k);

  std::cout << std::endl;
}