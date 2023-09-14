#include "../s21_list/s21_list.h"

using namespace std;

namespace s21 {
template <class T, typename Queue = s21::list<T>>
class queue {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const T &;
  using size_type = size_t;

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q) : queue_(q.queue_) {}
  queue(queue &&q) : queue_(std::move(q.queue_)) {}
  ~queue();
  void operator=(queue &&q);
  void operator=(const queue &q);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue &other);

 private:
  Queue queue_;
};
}  // namespace s21

#include "s21_queue.tpp"