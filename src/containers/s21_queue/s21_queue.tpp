namespace s21 {
template <typename value_type, typename Queue>
queue<value_type, Queue>::queue() : queue_() {}

template <typename value_type, typename Queue>
queue<value_type, Queue>::queue(std::initializer_list<value_type> const& items)
    : queue_(items) {}

template <typename value_type, typename Queue>
queue<value_type, Queue>::~queue() {
  queue_.~list();
}

template <typename value_type, typename Queue>
void queue<value_type, Queue>::operator=(queue&& l) {
  queue_ = std::move(l.queue_);
}

template <typename value_type, typename Queue>
void queue<value_type, Queue>::operator=(const queue& l) {
  queue_ = l.queue_;
}

template <typename value_type, typename Queue>
typename queue<value_type, Queue>::const_reference
queue<value_type, Queue>::front() {
  return queue_.front();
}

template <typename value_type, typename Queue>
typename queue<value_type, Queue>::const_reference
queue<value_type, Queue>::back() {
  return queue_.back();
}

template <typename value_type, typename Queue>
bool queue<value_type, Queue>::empty() {
  return queue_.size() == 0 ? true : false;
}

template <typename value_type, typename Queue>
typename queue<value_type, Queue>::size_type queue<value_type, Queue>::size() {
  return queue_.size();
}

template <typename value_type, typename Queue>
void queue<value_type, Queue>::push(const_reference value) {
  queue_.push_back(value);
}

template <typename value_type, typename Queue>
void queue<value_type, Queue>::pop() {
  queue_.pop_front();
}

template <typename value_type, typename Queue>
void queue<value_type, Queue>::swap(queue& other) {
  queue_.swap(other.queue_);
}
}  // namespace s21