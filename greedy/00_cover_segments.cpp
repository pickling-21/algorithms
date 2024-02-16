#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

/*Задача на программирование: покрыть отрезки точками
По данным и отрезкам необходимо найти множество точек минимального размера, для
которого каждый из отрезков содержит хотя бы одну из точек. В первой строке дано
число 1 ≤ n ≤ 100 отрезков. Каждая из последующих n строк содержит по два числа
0 ≤ l ≤ r ≤  10^9, задающих начало и конец отрезка. Выведите оптимальное число
m точек и сами m точек. Если таких множеств точек несколько, выведите любое из
них.

Sample Input 1:

3
1 3
2 5
3 6

Sample Output 1:

1
3
----
Sample Input 2:

4
4 7
1 3
2 5
5 6

Sample Output 2:

2
3 6

Если не получается разобраться с условием задачи, то попробуйте представить эту
задачу так:

есть несколько дощечек разной длины (это наши отрезки n). Нужно прибить их к
полу так, чтобы если комната перевернулась они не попадали. Вот минимальное
количество гвоздей в этой задаче и точки куда они прибиты и будет решением.

*/

typedef std::pair<int, int> Segment;

bool compare(const Segment& seg1, const Segment& seg2) {
  return seg1.second < seg2.second;
}

std::vector<int> get_covering_set(std::vector<Segment> segments) {
  std::vector<int> result;
  std::sort(segments.begin(), segments.end(), compare);
  int prev = segments[0].second;
  result.push_back(prev);
  for (std::size_t i = 1; i < segments.size(); i++) {
    if (prev < segments[i].first) {
      prev = segments[i].second;
      result.push_back(prev);
    }
  }
  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector<Segment> segments(segments_count);
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }

  std::vector<int> points = get_covering_set(segments);
  std::cout << points.size() << std::endl;
  for (std::size_t i = 0; i < points.size(); i++) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}