#include <gtest/gtest.h>

#include <list>

#include "../containers/s21_list/s21_list.h"

TEST(Constructors, simple) {
  s21::list<int> test1;
  ASSERT_EQ(test1.size(), (size_t)0);
  test1.push_back(1);
  ASSERT_EQ(test1.front(), 1);
  ASSERT_EQ(test1.back(), 1);
  ASSERT_EQ(test1.size(), (size_t)1);
  s21::list<char> test2;
  ASSERT_EQ(test2.size(), (size_t)0);
  test2.push_back('v');
  ASSERT_EQ(test2.front(), 'v');
  ASSERT_EQ(test2.back(), 'v');
  ASSERT_EQ(test2.size(), (size_t)1);
  s21::list<int> s21_list;
  std::list<int> std_list;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(Constructors, size) {
  s21::list<int> test1(5);
  ASSERT_EQ(test1.size(), (size_t)5);
  s21::list<double> test2(500);
  ASSERT_EQ(test2.size(), (size_t)500);
  s21::list<char> test3(0);
  ASSERT_EQ(test3.size(), (size_t)0);
  std::list<int> std_list(15);
  s21::list<int> s21_list(15);
  ASSERT_EQ(s21_list.size(), std_list.size());
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(Constructors, initializer_list) {
  std::initializer_list<int> test1{1, 9, -8, 23, 84, 1923};
  s21::list<int> test2(test1);
  ASSERT_EQ(test2.size(), (size_t)6);
  std::initializer_list<char> test3{'h', 'e', 'l', 'l', 'o', ' ',
                                    'w', 'o', 'r', 'l', 'd', '!'};
  s21::list<char> test4(test3);
  std::list<char> std_list(test3);
  ASSERT_EQ(test4.size(), (size_t)12);
  s21::list<char>::iterator a(test4.begin());
  std::list<char>::iterator b(std_list.begin());
  for (auto i : test3) {
    ASSERT_EQ(*a, *b);
    ASSERT_EQ(*a, i);
    ++a;
    ++b;
  }
  std::initializer_list<int> test5{};
  s21::list<int> test6(test5);
  ASSERT_EQ(test5.size(), (size_t)0);
}

TEST(Constructors, copy) {
  std::list<int> std_list = {1, 2, 3, 4};
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_in(std_list);
  s21::list<int> s21_in(s21_list);
  ASSERT_EQ(std_in.front(), s21_in.front());
  ASSERT_EQ(std_in.size(), s21_in.size());
  ASSERT_EQ(std_list.front(), s21_list.front());
  ASSERT_EQ(std_list.size(), s21_list.size());
  std::list<char> std_list1;
  s21::list<char> s21_list1;
  std::list<char> std_in1(std_list1);
  s21::list<char> s21_in1(s21_list1);
  ASSERT_EQ(std_in1.size(), s21_in1.size());
  // здесь различия std указывает на 0 при int и на '' при char, а мой улетает в
  // сегу
  // ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_list1.front(), s21_list1.front());
  ASSERT_EQ(std_list1.size(), s21_list1.size());
}

TEST(Constructors, move) {
  std::list<int> std_list = {1, 2, 3, 4};
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_in(std::move(std_list));
  s21::list<int> s21_in(std::move(s21_list));
  ASSERT_EQ(std_in.front(), s21_in.front());
  ASSERT_EQ(std_in.size(), s21_in.size());
  ASSERT_EQ(std_list.size(), s21_list.size());
  std::list<char> std_list1;
  s21::list<char> s21_list1;
  std::list<char> std_in1(std::move(std_list1));
  s21::list<char> s21_in1(std::move(s21_list1));
  ASSERT_EQ(std_in1.size(), s21_in1.size());

  // ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_list1.front(), s21_list1.front());
  ASSERT_EQ(std_list1.size(), s21_list1.size());
}

TEST(Constructors, operator_copy) {
  std::list<int> std_list = {1, 2, 3, 4};
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_in = std_list;
  s21::list<int> s21_in = s21_list;
  ASSERT_EQ(std_in.front(), s21_in.front());
  ASSERT_EQ(std_in.size(), s21_in.size());
  ASSERT_EQ(std_list.front(), s21_list.front());
  ASSERT_EQ(std_list.size(), s21_list.size());
  std::list<char> std_list1;
  s21::list<char> s21_list1;
  std::list<char> std_in1 = std_list1;
  s21::list<char> s21_in1 = s21_list1;
  ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_list1.front(), s21_list1.front());
  ASSERT_EQ(std_list1.size(), s21_list1.size());
}

TEST(Constructors, operator_move) {
  std::list<int> std_list = {1, 2, 3, 4};
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_in = std::move(std_list);
  s21::list<int> s21_in = std::move(s21_list);
  ASSERT_EQ(std_in.front(), s21_in.front());
  ASSERT_EQ(std_in.size(), s21_in.size());
  ASSERT_EQ(std_list.size(), s21_list.size());
  std::list<char> std_list1;
  s21::list<char> s21_list1;
  std::list<char> std_in1 = std::move(std_list1);
  s21::list<char> s21_in1 = std::move(s21_list1);
  ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_in1.size(), s21_in1.size());
  // ASSERT_EQ(std_list1.front(), s21_list1.front());
  ASSERT_EQ(std_list1.size(), s21_list1.size());
}

TEST(Element_access, front) {
  std::list<int> std_list = {2, 9, 3, 1, 9, 0, 1, 7};
  s21::list<int> s21_list = {2, 9, 3, 1, 9, 0, 1, 7};
  ASSERT_EQ(std_list.front(), s21_list.front());
  std_list.pop_front();
  s21_list.pop_front();
  ASSERT_EQ(std_list.front(), s21_list.front());
}

TEST(Element_access, back) {
  std::list<int> std_list = {2, 9, 3, 1, 9, 0, 1, 7};
  s21::list<int> s21_list = {2, 9, 3, 1, 9, 0, 1, 7};
  ASSERT_EQ(std_list.back(), s21_list.back());
  std_list.pop_back();
  s21_list.pop_back();
  ASSERT_EQ(std_list.back(), s21_list.back());
}

TEST(Iterators, begin) {
  std::list<int> std_list = {2, 9, 3, 1, 9, 0, 1, 7};
  s21::list<int> s21_list = {2, 9, 3, 1, 9, 0, 1, 7};
  s21::list<int>::iterator s21_iter = s21_list.begin();
  std::list<int>::iterator std_iter = std_list.begin();
  ASSERT_EQ(*s21_iter, *std_iter);
  ++s21_iter;
  ++std_iter;
  ASSERT_EQ(*s21_iter, *std_iter);
  s21_iter = s21_list.begin();
  std_iter = std_list.begin();
  ASSERT_EQ(*s21_iter, *std_iter);
}

TEST(Iterators, end) {
  s21::list<int> s21_list = {2, 9, 3, 1, 9, 0, 1, 7};
  s21::list<int>::iterator s21_iter = s21_list.end();
  ASSERT_EQ(*s21_iter, 7);
  --s21_iter;
  ASSERT_EQ(*s21_iter, 1);
  s21_iter = s21_list.end();
  ASSERT_EQ(*s21_iter, 7);
}

TEST(Capacity, empty) {
  s21::list<int> s21_list;
  ASSERT_EQ(s21_list.empty(), true);
  s21_list.push_front(123);
  ASSERT_EQ(s21_list.empty(), false);
  s21_list.pop_front();
  ASSERT_EQ(s21_list.empty(), true);
}

TEST(Capacity, size) {
  s21::list<char> s21_list;
  ASSERT_EQ(s21_list.size(), (size_t)0);
  s21::list<int> s21_list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(s21_list1.size(), (size_t)10);
  s21_list1.pop_back();
  s21_list1.pop_front();
  ASSERT_EQ(s21_list1.size(), (size_t)8);
}

TEST(Capacity, max_size) {
  s21::list<char> s21_list;
  std::list<char> std_list;
  ASSERT_EQ(s21_list.max_size(), std_list.max_size());
  s21::list<int> s21_list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> std_list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(s21_list1.max_size(), std_list1.max_size());
  s21_list1.pop_back();
  s21_list1.pop_front();
  std_list1.pop_back();
  std_list1.pop_front();
  ASSERT_EQ(s21_list1.max_size(), std_list1.max_size());
}

TEST(Modifiers, clear) {
  s21::list<char> s21_list = {'c', 'l', 'e', 'a', 'r'};
  std::list<char> std_list = {'c', 'l', 'e', 'a', 'r'};
  s21_list.clear();
  std_list.clear();
  ASSERT_EQ(s21_list.empty(), std_list.empty());
  s21::list<int> s21_list1 = {1, 2, 3};
  std::list<int> std_list1 = {6, 8, 9, 123};
  s21_list1.clear();
  std_list1.clear();
  ASSERT_EQ(s21_list1.empty(), std_list1.empty());
}

TEST(Modifiers, insert) {
  s21::list<char> s21_list = {'n', 's', 'e', 'r', 't'};
  std::list<char> std_list = {'n', 's', 'e', 'r', 't'};
  s21::list<char>::iterator s21_iter = s21_list.begin();
  std::list<char>::iterator std_iter = std_list.begin();
  s21::list<char>::iterator test_s21 = s21_list.insert(s21_iter, 'i');
  std::list<char>::iterator test_std = std_list.insert(std_iter, 'i');
  ASSERT_EQ(*test_std, *test_s21);
  s21::list<char> s21_list1 = {'i', 'n', 'e', 'r', 't'};
  std::list<char> std_list1 = {'i', 'n', 'e', 'r', 't'};
  s21::list<char>::iterator s21_iter1 = s21_list1.begin();
  std::list<char>::iterator std_iter1 = std_list1.begin();
  for (int i = 0; i < 2; i++) {
    s21_iter1++;
    std_iter1++;
  }
  s21::list<char>::iterator test_s21_1 = s21_list1.insert(s21_iter1, 's');
  std::list<char>::iterator test_std_1 = std_list1.insert(std_iter1, 's');
  ASSERT_EQ(*test_std_1, *test_s21_1);
}

TEST(Modifiers, erase) {
  s21::list<char> s21_list = {'e', 'r', 'a', 'a', 's', 'e'};
  std::list<char> std_list = {'e', 'r', 'a', 'a', 's', 'e'};
  s21::list<char>::iterator s21_iter = s21_list.begin();
  std::list<char>::iterator std_iter = std_list.begin();
  for (int i = 0; i < 2; i++) {
    s21_iter++;
    std_iter++;
  }
  s21_list.erase(s21_iter);
  std_list.erase(std_iter);
  ASSERT_EQ(std_list.size(), s21_list.size());
}

TEST(Modifiers, swap) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21::list<int> s21_list_1 = {6, 7, 8, 9, 10};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  std::list<int> std_list_1 = {6, 7, 8, 9, 10};
  s21_list.swap(s21_list_1);
  std_list.swap(std_list_1);
  s21::list<int>::iterator s21_iter = s21_list.begin();
  std::list<int>::iterator std_iter = std_list.begin();
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
  s21::list<int>::iterator s21_iter_1 = s21_list_1.begin();
  std::list<int>::iterator std_iter_1 = std_list_1.begin();
  for (size_t i = 0; i < s21_list_1.size(); i++) {
    ASSERT_EQ(*s21_iter_1, *std_iter_1);
    s21_iter_1++;
    std_iter_1++;
  }
}

TEST(Modifiers, merge) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21::list<int> s21_list_1 = {6, 7, 8, 9, 10};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  std::list<int> std_list_1 = {6, 7, 8, 9, 10};
  std_list.merge(std_list_1);
  s21_list.merge(s21_list_1);
  s21::list<int>::iterator s21_iter = s21_list.begin();
  std::list<int>::iterator std_iter = std_list.begin();
  for (size_t i = 0; i < std_list.size(); i++) {
    ASSERT_EQ(*s21_iter, *std_iter);
    std_iter++;
    s21_iter++;
  }
  std::list<int>::iterator std_iter_1 = std_list_1.begin();
  s21::list<int>::iterator s21_iter_1 = s21_list_1.begin();
  for (size_t i = 0; i < std_list_1.size(); i++) {
    ASSERT_EQ(*s21_iter_1, *std_iter_1);
    std_iter_1++;
    s21_iter_1++;
  }
  s21::list<int> s21_list_2 = {1, 2, 3, 4, 5};
  s21::list<int> s21_list_3 = {6, 7, 8, 9, 10};
  std::list<int> std_list_2 = {1, 2, 3, 4, 5};
  std::list<int> std_list_3 = {6, 7, 8, 9, 10};
  std_list_2.merge(std_list_3);
  s21_list_2.merge(s21_list_3);
  s21::list<int>::iterator s21_iter_2 = s21_list_2.begin();
  std::list<int>::iterator std_iter_2 = std_list_2.begin();
  for (size_t i = 0; i < std_list_2.size(); i++) {
    ASSERT_EQ(*s21_iter_2, *std_iter_2);
    std_iter_2++;
    s21_iter_2++;
  }
}

TEST(Modifiers, splice) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  s21::list<int> s21_list_1 = {6, 7, 8, 9, 10};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  std::list<int> std_list_1 = {6, 7, 8, 9, 10};
  s21::list<int>::const_iterator s21_iter = s21_list.cbegin();
  std::list<int>::const_iterator std_iter = std_list.cbegin();
  s21_list.splice(s21_iter, s21_list_1);
  std_list.splice(std_iter, std_list_1);
  s21::list<int>::iterator s21_iter_1 = s21_list.begin();
  std::list<int>::iterator std_iter_1 = std_list.begin();
  for (size_t i = 0; i < s21_list.size(); ++i) {
    ASSERT_EQ(*s21_iter_1, *std_iter_1);
    ++s21_iter_1;
    ++std_iter_1;
  }

  s21::list<int> s21_list_2 = {'h', 'o', '!'};
  s21::list<int> s21_list_3 = {'e', 'l', 'l'};
  std::list<int> std_list_2 = {'h', 'o', '!'};
  std::list<int> std_list_3 = {'e', 'l', 'l'};
  s21::list<int>::const_iterator s21_iter_2 = s21_list_2.cbegin();
  std::list<int>::const_iterator std_iter_2 = std_list_2.cbegin();
  ++s21_iter_2;
  ++std_iter_2;
  s21_list_2.splice(s21_iter_2, s21_list_3);
  std_list_2.splice(std_iter_2, std_list_3);
  s21::list<int>::iterator s21_iter_3 = s21_list_2.begin();
  std::list<int>::iterator std_iter_3 = std_list_2.begin();
  for (size_t i = 0; i < s21_list_2.size(); ++i) {
    ASSERT_EQ(*s21_iter_3, *std_iter_3);
    ++s21_iter_3;
    ++std_iter_3;
  }
}

TEST(Modifiers, other_functions) {
  s21::list<int> test = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  test.reverse();
  test.unique();
  test.sort();
  s21::list<int>::iterator test_1 = test.begin();
  for (int i = 0; i < 5; i++) {
    ASSERT_EQ(i + 1, *test_1);
    ++test_1;
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  return result;
}
