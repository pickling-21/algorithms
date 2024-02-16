/*
Задача на программирование: различные
слагаемые
По данному числу 1 ≤ n ≤ 10^9 найдите максимальное число k, для которого n можно
представить как сумму k различных натуральных слагаемых. Выведите в первой
строке число k, во второй — k слагаемых.

Sample Input 1:

4

Sample Output 1:

2
1 3
---
Sample Input 2:

6
Sample Output 2:

3
1 2 3

*/

#include <iostream>
#include <vector>

std::vector<int> get_terms(int n) {
  std::vector<int> result;
  for (int i = 1; i <= n; i++) {
    int temp = n - i;
    if (temp >= i + 1) {
      result.push_back(i);
      n = temp;
    } else {
      result.push_back(n);
      break;
    }
  }
  return result;
}

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> terms = get_terms(n);

  std::cout << terms.size() << std::endl;
  for (int term : terms) std::cout << term << " ";
  std::cout << std::endl;
}