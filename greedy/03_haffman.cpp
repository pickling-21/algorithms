/*По данной непустой строке s длины не более 10^4, состоящей из строчных
букв латинского алфавита, постройте оптимальный беспрефиксный код.
В первой строке выведите количество различных букв k,
встречающихся в строке, и размер получившейся закодированной строки.
В следующих k строках запишите коды букв в формате "letter: code". В последней
строке выведите закодированную строку.

Sample Input 1:

a

Sample Output 1:

1 1
a: 0
0
Sample Input 2:

abacabad

Sample Output 2:

4 14
a: 0
b: 10
c: 110
d: 111
01001100100111


https://www.geeksforgeeks.org/make_heap-in-cpp-stl/
https://habr.com/ru/articles/144200/
https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
*/

#include <iostream>
#include <map>
#include <queue>
#include <string>

struct Node {
  char data_;
  int freq_;
  Node *left_ = nullptr;
  Node *right_ = nullptr;
  Node(char data, int freq) : data_(data), freq_(freq){};
};

void printBT(const std::string &prefix, const Node *node, bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    std::cout << "|" << node->data_ << "|"
              << "(" << node->freq_ << ")" << std::endl;

    // enter the next tree level - left and right branch
    printBT(prefix + (isLeft ? "│   " : "    "), node->left_, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right_, false);
  }
}

void printBT(const Node *node) { printBT("", node, false); }

struct Compare {
  bool operator()(Node *l, Node *r) { return l->freq_ > r->freq_; }
};

void print_pq(std::priority_queue<Node *, std::vector<Node *>, Compare> q1) {
  while (!q1.empty()) {
    std::cout << q1.top()->data_ << " " << q1.top()->freq_ << std::endl;
    q1.pop();
  }
  std::cout << "end" << std::endl;
}

std::map<char, int> fin_freq(std::string str) {
  std::map<char, int> mp;
  for (char s : str) {
    mp[s]++;
  }
  return mp;
}

void generate_code(Node *node, std::string str,
                   std::map<char, std::string> &result) {
  if (node == nullptr) return;
  if (node->data_ != '$') {
    result[node->data_] = str;
  }
  generate_code(node->left_, str + '0', result);
  generate_code(node->right_, str + '1', result);
}

std::string generate_code(Node *node, std::map<char, std::string> &result,
                          const std::string &str) {
  std::string ans = "";
  if (!node->left_ && !node->right_) {
    result[node->data_] = '0';
  } else {
    generate_code(node, "", result);
  }
  for (auto ch : str) {
    ans.append(result[ch]);
  }
  return ans;
}

std::map<char, std::string> get_code(std::string &str, std::string &out) {
  std::map<char, std::string> result;

  std::map<char, int> freq = fin_freq(str);

  std::priority_queue<Node *, std::vector<Node *>, Compare> pq;

  for (auto f : freq) {
    pq.push(new Node(f.first, f.second));
  }

  while (pq.size() != 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    Node *node = new Node('$', right->freq_ + left->freq_);

    node->left_ = left;
    node->right_ = right;

    pq.push(node);
  }

  printBT(pq.top());
  std::cout << "----";

  out = generate_code(pq.top(), result, str);

  return result;
}

int main() {
  std::string str;
  std::cin >> str;
  std::string out = "";
  std::map<char, std::string> result = get_code(str, out);
  std::cout << result.size() << " " << out.length() << std::endl;
  for (auto r : result) {
    std::cout << r.first << ": " << r.second << std::endl;
  }
  std::cout << out << std::endl;
}
