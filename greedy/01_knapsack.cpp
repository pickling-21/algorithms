/*
Задача на программирование: непрерывный рюкзак
Первая строка содержит количество предметов 1 ≤ n ≤ 10^3 и вместимость рюкзака
0 ≤ W ≤ 2 · 10^6. Каждая из следующих n строк задаёт стоимость
0 ≤ c(i) ≤ 2 ·10 ^6 и объём 0 < w(i) < 2 · 10^6 предмета (n, W, c(i), w(i) —
целые числа). Выведите максимальную стоимость частей предметов (от каждого
предмета можно отделить любую часть, стоимость и объём при этом пропорционально
уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков
после запятой.

Sample Input:

3 50
60 20
100 50
120 30

Sample Output:

180.000

*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

typedef std::pair<int, int> Item;

double get_cost(std::vector<Item> &items, int W) {
  double result = 0;
  std::sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
    return (a.first / (double)a.second) > (b.first / (double)b.second);
  });

  for (auto it : items) {
    double item_w = it.second;
    if (W < item_w) {
      // take what i can
      result += (it.first / item_w) * W;
      item_w = W;
    } else {
      // take all
      result += it.first;
    }
    W -= item_w;
    if (W <= 0) break;
  }
  return result;
}

int main(void) {
  int item_count;
  int W;
  std::cin >> item_count >> W;
  std::vector<Item> items(item_count);

  for (int i = 0; i < item_count; i++) {
    std::cin >> items[i].first >> items[i].second;
  }

  double cost = get_cost(items, W);
  std::cout << std::fixed << std::setprecision(3) << cost << std::endl;
}