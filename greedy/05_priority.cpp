#include <iostream>
#include <vector>

class MinHeap {
 public:
  using size_type = std::size_t;
  size_type HeapSize() { return arr_.size(); };
  // MinHeap() { arr_.push_back(INT32_MIN); }

  int find(int x) { return 0; }
  void Swap(int i, int j){};
  void ShiftDown(){};
  void ShiftUp(){};

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
    while (arr_[parent] > arr_[i] && i > 0) {
      std::swap(arr_[parent], arr_[i]);
      i = parent;
      parent = (i - 1) / 2;
      this->print();
    }
  };

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
  MinHeap a;

  // 4  18 7  20  21  18  42  53  22
  a.Insert(4);
  // a.print();

  a.Insert(18);
  // a.print();

  a.Insert(7);
  // a.print();

  a.Insert(20);
  // a.print();

  a.Insert(21);
  std::cout << "ABOBA \n\n";
  a.print();

  a.Insert(1);
  a.print();
  int n = 0;
  // std::cin >> n;

  // for (int i = 0; i < 0; ++i) {
  //   std::string operation;
  //   int num;
  //   std::cin >> operation >> num;
  //   if (operation == "Insert") {
  //   } else if (operation == "ExtractMax") {
  //   }
  // }

  return 0;
}