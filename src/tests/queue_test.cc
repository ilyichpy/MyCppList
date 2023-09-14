#include <queue>

#include "tests.h"

TEST(Container_queue, simple) {
  s21::queue<int> test_s21;
  std::queue<int> test_std;
  ASSERT_EQ(test_s21.size(), test_std.size());
  test_s21.push(3);
  test_std.push(3);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.front(), test_std.front());
  ASSERT_EQ(test_s21.back(), test_std.back());
  test_s21.push(5);
  test_std.push(5);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.front(), test_std.front());
  ASSERT_EQ(test_s21.back(), test_std.back());
}

TEST(Container_queue, initializer_list) {
  std::initializer_list<int> init = {6, 5, 4, 3, 2, 1};
  s21::queue<int> test_s21(init);
  std::queue<int> test_std(init);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.front(), test_std.front());
  ASSERT_EQ(test_s21.back(), test_std.back());
  std::initializer_list<int> init_1 = {};
  s21::queue<int> test_s21_1(init_1);
  std::queue<int> test_std_1(init_1);
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
}

TEST(Container_queue, copy) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::queue<int> test_s21(a);
  std::queue<int> test_std(a);
  s21::queue<int> test_s21_1(test_s21);
  std::queue<int> test_std_1(test_std);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.front(), test_std.front());
  ASSERT_EQ(test_s21.back(), test_std.back());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
}

TEST(Container_queue, move) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::queue<int> test_s21(a);
  std::queue<int> test_std(a);
  s21::queue<int> test_s21_1(std::move(test_s21));
  std::queue<int> test_std_1(std::move(test_std));
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
}

TEST(Container_queue, equals) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::queue<int> test_s21(a);
  std::queue<int> test_std(a);
  s21::queue<int> test_s21_1 = test_s21;
  std::queue<int> test_std_1 = test_std;
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21.front(), test_std.front());
  ASSERT_EQ(test_s21.back(), test_std.back());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
  std::initializer_list<int> b = {49, 21, 2, 3, 499, 1, 34, 234};
  s21::queue<int> test_s21_2(b);
  std::queue<int> test_std_2(b);
  test_s21_1 = test_s21_2;
  test_std_1 = test_std_2;
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
  ASSERT_EQ(test_s21_2.front(), test_std_2.front());
  ASSERT_EQ(test_s21_2.back(), test_std_2.back());
}

TEST(Container_queue, equals_2) {
  std::initializer_list<int> a = {1, 2, 3, 4, 5};
  s21::queue<int> test_s21(a);
  std::queue<int> test_std(a);
  s21::queue<int> test_s21_1 = std::move(test_s21);
  std::queue<int> test_std_1 = std::move(test_std);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
  std::initializer_list<int> b = {49, 21, 2, 3, 499, 1, 34, 234};
  s21::queue<int> test_s21_2(b);
  std::queue<int> test_std_2(b);
  test_s21_1 = std::move(test_s21_2);
  test_std_1 = std::move(test_std_2);
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
}

TEST(Modifiers_queue, empty) {
  s21::queue<int> test_s21;
  std::queue<int> test_std;
  ASSERT_EQ(test_s21.empty(), test_std.empty());
  test_s21.push(1);
  test_std.push(1);
  ASSERT_EQ(test_s21.empty(), test_std.empty());
}

TEST(Modifiers_queue, swap) {
  std::initializer_list<char> a = {'h', 'e', 'l', 'l', 'o'};
  std::initializer_list<char> b = {'s', 'w', 'a', 'p'};
  s21::queue<char> test_s21(a);
  std::queue<char> test_std(a);
  s21::queue<char> test_s21_1;
  std::queue<char> test_std_1;
  test_s21.swap(test_s21_1);
  test_std.swap(test_std_1);
  ASSERT_EQ(test_s21.size(), test_std.size());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
  s21::queue<char> test_s21_2(b);
  std::queue<char> test_std_2(b);
  test_s21_2.swap(test_s21_1);
  test_std_2.swap(test_std_1);
  ASSERT_EQ(test_s21_2.size(), test_std_2.size());
  ASSERT_EQ(test_s21_2.front(), test_std_2.front());
  ASSERT_EQ(test_s21_2.back(), test_std_2.back());
  ASSERT_EQ(test_s21_1.size(), test_std_1.size());
  ASSERT_EQ(test_s21_1.front(), test_std_1.front());
  ASSERT_EQ(test_s21_1.back(), test_std_1.back());
}