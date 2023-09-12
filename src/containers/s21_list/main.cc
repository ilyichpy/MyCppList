#include <list>

#include "s21_list.h"

using namespace s21;

int main() {
 s21::list<int> test = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  test.reverse();
  test.unique();
//   test.sort();
  //   s21::list<int> s21_list_1 = {6, 7, 8, 9, 10};
  //   std::list<int> std_list = {1, 2, 3, 4, 5};
  //   std::list<int> std_list_1 = {6, 7, 8, 9, 10};
  //   s21::list<int>::const_iterator s21_iter = s21_list.cbegin();
  //   std::list<int>::const_iterator std_iter = std_list.cbegin();
  //   s21_list.splice(s21_iter, s21_list_1);
  //   std_list.splice(std_iter, std_list_1);
  //   s21::list<int>::iterator s21_iter_1 = s21_list.begin();
  //   std::list<int>::iterator std_iter_1 = std_list.begin();
  //   for (size_t i = 0; i < s21_list.size(); ++i) {
  //     std::cout << " " << *std_iter_1 << std::endl;
  //     ++std_iter_1;
  //   }
  //   s21::list<int>::iterator s21_iter_1 = s21_list_1.begin();
  //   std::list<int>::iterator std_iter_1 = std_list_1.begin();
  //   for (size_t i = 0; i < s21_list_1.size(); i++) {
  //     std::cout << *s21_iter_1 << " " << *std_iter_1 << std::endl;
  //     s21_iter_1++;
  //     std_iter_1++;
  //   }

  return 0;
}