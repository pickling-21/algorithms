#include <iostream>
#include <vector>

class MinHeap {
 public:
  using size_type = std::size_t;
  size_type HeapSize() { return arr_.size(); };
  // MinHeap() { arr_.push_back(INT32_MIN); }

  bool IsValid_Index(int i) { return i <= arr_.size(); }
  void Swap(int i, int j){};
  void ShiftDown(int i) {
    for (; i < arr_.size(); ++i) {
      int parent = i;
      int left = i * 2 + 1;
      int right = i * 2 + 2;
      if (arr_[parent] < arr_[left]) {
        std::swap(arr_[parent], arr_[left]);
      } else if (arr_[parent] < arr_[right]) {
        std::swap(arr_[parent], arr_[left]);
      }
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
    this->print();

    while (arr_[parent] < arr_[i] && i > 0) {
      std::swap(arr_[parent], arr_[i]);
      i = parent;
      parent = (i - 1) / 2;
      this->print();
    }
    std::cout << "AAAAAAAAAAAAAAA\n";
  };

  void ExtractMax() {
    std::cout << arr_[0] << std::endl;
    for (size_type i = 1; i < arr_.size(); ++i) {
        }
    arr_.pop_back();
  }

  void print() {
    for (int a : arr_) {
      std::cout << a << ' ';
    }
    std::cout << "\n----------" << std::endl;
  }

 private:
  std::vector<int> arr_;
};

int main() {
  MinHeap heap;

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