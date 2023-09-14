#include <initializer_list>
#include <iostream>
#include <limits>

using namespace std;

namespace s21 {
template <class T>
class stack {
 public:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  stack() : head_(nullptr), size_(0) {}
  stack(std::initializer_list<value_type> const& items);
  stack(const stack& s);
  stack(stack&& s);
  ~stack();
  void operator=(stack&& s);
  void operator=(const stack& s);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack& other);

 private:
  template <typename value_type>
  class Node {
   public:
    value_type data;
    Node* pNext_;
    Node(value_type data, Node* pNext = nullptr) : data(data), pNext_(pNext) {}
  };

  Node<T>* head_;
  size_type size_;
};
}  // namespace s21

#include "s21_stack.tpp"