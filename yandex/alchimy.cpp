#include <array>
#include <iostream>
#include <map>
#include <vector>

void print_recipe(std::vector<int> recipe) {
  for (int ing : recipe) {
    std::cout << ing << " ";
  }
  std::cout << std::endl;
}

// говорит возможен ли рецепт и количество ингредиентов нужных для него
bool find_recursive(const std::map<int, int>& recipes, int& ones, int& twoes,
                    int s, int start) {
  for (auto recipe : recipes) {
    int ing = recipe.first;
    int count = recipe.second;
    if (ing == start) {
      return false;
    }
  }
  int n = s - 3;

  if (ing == 1) {
    ones += count;
  } else if (ing == 2) {
    twoes += count;
  } else if (ing == start) {
    // start в формате z
    // закольцевались
    return false;
  } else {
    return find_recursive(freqs, ones, twoes, ing, start);
  }
};

bool find_recipie(const std::vector<std::map<int, int>>& freqs, int X, int Y,
                  int S) {
  int ones = 0;
  int twoes = 0;
  bool res = find_recursive(freqs, ones, twoes, S, S);
  std::cout << "ones " << ones << " twoes " << twoes << std::endl;
  return res && ones <= X && twoes <= Y;
};

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<int>> book(n - 2,
                                     std::vector<int>());  // один размер

  for (int i = 0; i < n - 2; ++i) {
    int ingregienst_count = 0;
    std::cin >> ingregienst_count;
    std::vector<int> ingredients;
    for (int j = 0; j < ingregienst_count; ++j) {
      int ingredient = 0;
      std::cin >> ingredient;
      ingredients.push_back(ingredient);
    }
    book[i] = ingredients;
  }

  int questions_count = 0;

  std::vector<std::map<int, int>> freqs(n - 2, std::map<int, int>());
  int j = 0;
  for (auto page : book) {
    std::map<int, int> recipe;
    for (int ing : page) {
      recipe[ing]++;  // нашли частоту ингредиентов
    };
    freqs[j] = recipe;
    ++j;
  }

  //   for (auto b : freqs[0]) {
  //     std::cout << b.first << " ";
  //   }

  std::cin >> questions_count;
  for (int i = 0; i < questions_count; ++i) {
    int X = 0;
    int Y = 0;
    int S = 0;
    std::cin >> X >> Y >> S;
    bool res = find_recipie(freqs, X, Y, S);
    std::cout << res;
  };

  int i = 3;
  //   for (auto a : freqs) {
  //     std::cout << i << "| ";

  //     std::cout << std::endl;
  //     ++i;
  //   }

  return 0;
}