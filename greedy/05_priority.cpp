#include <iostream>
#include <vector>

class MaxHeap {
 public:
  using size_type = std::size_t;
  size_type HeapSize() { return arr_.size(); };
  // MinHeap() { arr_.push_back(INT32_MIN); }

  void ShiftDown(int i) {
    int size = arr_.size();
    while (i < size) {
      std::cout << "ASASASASASA\n\n";
      int parent = Parent(i);
      int left = Left(i);
      int right = Right(i);
      if (left < size && right < size) {
        std::cout << "1AAAAA" << std::endl;

        if (arr_[i] > arr_[left] || arr_[i] > arr_[right]) {
          if (arr_[left] > arr_[right]) {
            std::swap(arr_[i], arr_[left]);
            std::cout << "1!!!!!!@" << std::endl;

            i = left;
          } else {
            std::swap(arr_[i], arr_[right]);
            std::cout << "1!!!!!!@" << std::endl;

            i = right;
          }
        } else {
          break;
        }
      } else if (left < size && arr_[left] > arr_[i]) {
        std::swap(arr_[left], arr_[i]);
        std::cout << "1!!!!!!@" << std::endl;
        i = left;

      } else if (right < size && arr_[right] > arr_[i]) {
        std::swap(arr_[right], arr_[i]);
        std::cout << "1!!!!!!@" << std::endl;

        i = right;

      } else {
        std::cout << "1!!!!!!@" << std::endl;

        break;  // не с кем менять
      }
      this->print();
    }
  };

  void Insert(int x) {
    size_type i = arr_.size();
    size_type parent = (i - 1) / 2;
    // минус один чтобы не было смещения
    // например [10, 20, 30]. По идее 10 корень 20 и 30 дочерние узлы
    // если использовать i/2, то 30 окажется дочерним узлом 20 (2/2 = 1)
    // а если использовать правильно (i - 1) / 2  то все будет ок (2 - 1 ) / 2 =
    // 0 значит 30 окажется дочкой 10 что верно!
    arr_.push_back(x);

    while (arr_[parent] < arr_[i] && i > 0) {
      std::swap(arr_[parent], arr_[i]);
      i = parent;
      parent = (i - 1) / 2;
    };
  };

  void ExtractMax() {
    std::cout << arr_[0] << std::endl;

    arr_[0] = arr_[arr_.size() - 1];
    arr_.pop_back();

    ShiftDown(0);
  }

  void print() {
    for (int a : arr_) {
      std::cout << a << ' ';
    }
    std::cout << "\n----------" << std::endl;
  }

 private:
  int Parent(int i) { return (i - 1) / 2; };
  int Left(int i) { return i * 2 + 1; };
  int Right(int i) { return i * 2 + 2; };

 private:
  std::vector<int> arr_;
};

int main() {
  MaxHeap heap;

  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::string operation;
    std::cin >> operation;
    if (operation == "Insert") {
      int num;
      std::cin >> num;
      heap.Insert(num);
    } else if (operation == "ExtractMax") {
      heap.ExtractMax();
    }
  }

  return 0;
}