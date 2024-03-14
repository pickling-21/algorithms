/*Бронирование переговорки
Задано n интервалов. Требуется найти максимальное количество взаимно
непересекающихся интервалов.

Два интервала пересекаются, если они имеют хотя бы одну общую точку.

Формат ввода
В первой строке задано одно число n(1≤n≤100) — количество интервалов.

В следующих n строках заданы интервалы li, ri (1≤li≤ri≤50).

Формат вывода
Выведите ответ на задачу.

Ввод
3
1 3
2 3
4 5
Вывод
2

*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using Segment = std::pair<int, int>;

int compare(const Segment &a, const Segment &b) { return a.second < b.second; }

int max_booking(std::vector<Segment> segments) {
  int ans = 1;
  std::sort(segments.begin(), segments.end(), compare);
  Segment last = segments[0];
  for (int i = 1; i < segments.size(); ++i) {
    if (last.second < segments[i].first) {
      last = segments[i];
      ans++;
    }
  }
  return ans;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector<Segment> segments(segments_count);
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }

  int max_segments = max_booking(segments);
  std::cout << max_segments << std::endl;
}