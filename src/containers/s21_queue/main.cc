#include <initializer_list>
#include <queue>

#include "s21_queue.h"

int main() {
  std::initializer_list<int> init_1 = {};
  s21::queue<int> test_s21_1(init_1);
  std::queue<int> test_std_1(init_1);
  std::cout << test_std_1.size() << std::endl;
  std::cout << test_std_1.front() << std::endl;
  std::cout << test_std_1.back() << std::endl;
  return 0;
}