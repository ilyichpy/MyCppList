#include <stack>

#include "s21_stack.h"

int main() {
  std::initializer_list<int> a = {1, 2, 3};
  std::initializer_list<int> a1 = {4, 5};
  s21::stack<int> b(a);
  s21::stack<int> c(a1);
  std::stack<int> d(a);
  std::stack<int> d1(a1);
  d.swap(d1);
  b.swap(c);
  std::cout << d1.size() << std::endl;
  std::cout << c.size() << std::endl;
  return 0;
}