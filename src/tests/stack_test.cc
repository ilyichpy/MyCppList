#include <stack>

#include "tests.h"

TEST(Container_stack, simple) {
  s21::stack<int> test_s21;
  std::stack<int> test_std;
  ASSERT_EQ(test_s21.size(), test_std.size());
  test_s21.push(3);
  test_std.push(3);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.top(), test_std.top());
  test_s21.push(5);
  test_std.push(5);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.top(), test_std.top());
}

TEST(Container_stack, initializer_list) {
  std::initializer_list<int> init = {6, 5, 4, 3, 2, 1};
  s21::stack<int> test_s21(init);
  std::stack<int> test_std(init);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.top(), test_std.top());
  std::initializer_list<int> init_1 = {};
  s21::stack<int> test_s21_1(init_1);
  std::stack<int> test_std_1(init_1);
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
}

TEST(Container_stack, copy) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::stack<int> test_s21(a);
  std::stack<int> test_std(a);
  s21::stack<int> test_s21_1(test_s21);
  std::stack<int> test_std_1(test_std);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.top(), test_std.top());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
}

TEST(Container_stack, move) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::stack<int> test_s21(a);
  std::stack<int> test_std(a);
  s21::stack<int> test_s21_1(std::move(test_s21));
  std::stack<int> test_std_1(std::move(test_std));
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
}

TEST(Container_stack, equals) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::stack<int> test_s21(a);
  std::stack<int> test_std(a);
  s21::stack<int> test_s21_1 = test_s21;
  std::stack<int> test_std_1 = test_std;
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.top(), test_std.top());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
  std::initializer_list<int> b = {49, 21, 2, 3, 499, 1, 34, 234};
  s21::stack<int> test_s21_2(b);
  std::stack<int> test_std_2(b);
  test_s21_1 = test_s21_2;
  test_std_1 = test_std_2;
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
  ASSERT_EQ(test_s21_2.top(), test_std_2.top());
}

TEST(Container_stack, equals_2) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::stack<int> test_s21(a);
  std::stack<int> test_std(a);
  s21::stack<int> test_s21_1 = std::move(test_s21);
  std::stack<int> test_std_1 = std::move(test_std);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
  std::initializer_list<int> b = {49, 21, 2, 3, 499, 1, 34, 234};
  s21::stack<int> test_s21_2(b);
  std::stack<int> test_std_2(b);
  test_s21_1 = std::move(test_s21_2);
  test_std_1 = std::move(test_std_2);
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
}

TEST(Modifiers_stack, empty) {
  s21::stack<int> test_s21;
  std::stack<int> test_std;
  ASSERT_EQ(test_s21.empty(), test_std.empty());
  test_s21.push(1);
  test_std.push(1);
  ASSERT_EQ(test_s21.empty(), test_std.empty());
}

TEST(Modifiers_stack, swap) {
  std::initializer_list<char> a = {'h', 'e', 'l', 'l', 'o'};
  std::initializer_list<char> b = {'s', 'w', 'a', 'p'};
  s21::stack<char> test_s21(a);
  std::stack<char> test_std(a);
  s21::stack<char> test_s21_1;
  std::stack<char> test_std_1;
  test_s21.swap(test_s21_1);
  test_std.swap(test_std_1);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
  s21::stack<char> test_s21_2(b);
  std::stack<char> test_std_2(b);
  test_s21_2.swap(test_s21_1);
  test_std_2.swap(test_std_1);
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
  ASSERT_EQ(test_s21_2.top(), test_std_2.top());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.top(), test_std_1.top());
}