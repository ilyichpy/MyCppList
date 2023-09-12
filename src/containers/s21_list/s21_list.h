#include <initializer_list>
#include <iostream>
#include <limits>

#if defined(linux) || defined(__linux)
#define MAX_SIZE 2
#endif

#if __APPLE__
#define MAX_SIZE 1
#endif

using namespace std;

namespace s21 {
template <class T>
class list {
 public:
  // Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  // containers
  list() : head_(nullptr), tail_(nullptr), size_(0) {}
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  void operator=(list&& l);
  void operator=(const list& l);

  // Element access
  const_reference front();
  const_reference back();

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void clear();
  void push_back(const_reference value) noexcept;
  void pop_back();
  void push_front(const_reference value) noexcept;
  void pop_front();
  void swap(list& other);

 private:
  template <class type_>
  class Node {
   public:
    type_ data;
    Node* pNext;
    Node* pPrev;

    Node(type_ data, Node* pNext = nullptr, Node* pPrev = nullptr)
        : data(data), pNext(pNext), pPrev(pPrev) {}
  };

  Node<T>* head_;
  Node<T>* tail_;
  size_type size_;

 public:
  class ListIterator {
    friend class list<value_type>;

   public:
    ListIterator() { ptr = nullptr; }
    ListIterator(Node<value_type>* ptr_) : ptr(ptr_) {}
    reference operator*() const;
    value_type* operator->() const;
    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;
    bool operator>(const ListIterator& other) const;
    bool operator>=(const ListIterator& other) const;
    bool operator<(const ListIterator& other) const;
    bool operator<=(const ListIterator& other) const;
    ListIterator operator+(size_type n) const;
    ListIterator operator-(size_type n) const;

   private:
    Node<value_type>* ptr;
  };

  class ListConstIterator : public ListIterator {
    friend class list<value_type>;

   public:
    ListConstIterator() { const_ptr = nullptr; }
    ListConstIterator(Node<value_type>* ptr_) : const_ptr(ptr_) {}
    const_reference operator*() const;
    ListConstIterator& operator++();
    ListConstIterator operator++(int);
    ListConstIterator& operator--();
    ListConstIterator operator--(int);

   private:
    Node<value_type>* const_ptr;
  };

  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  // iterators
  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
};
};  // namespace s21

#include "s21_modifiers.tpp"
