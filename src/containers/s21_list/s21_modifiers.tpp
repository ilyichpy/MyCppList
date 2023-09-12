namespace s21 {
template <typename value_type>
list<value_type>::list(size_type n) : head_(nullptr), tail_(nullptr), size_(n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& item : items) {
    push_back(item);
  }
}

template <typename value_type>
list<value_type>::list(const list& l)
    : head_(nullptr), tail_(nullptr), size_(0) {
  size_ = l.size_;
  Node<value_type>* tmp = l.head_;

  for (size_type i = 0; i < l.size_; ++i) {
    push_back(tmp->data);
    tmp = tmp->pNext;
  }
}
template <typename value_type>
list<value_type>::list(list&& l)
    : head_(l.head_), tail_(l.tail_), size_(l.size_) {
  l.head_ = nullptr;
  l.tail_ = nullptr;
  l.size_ = 0;
}

template <typename value_type>
list<value_type>::~list() {
  // clear();
  size_type size_this = size_;
  for (size_type i = 0; i < size_this; ++i) {
    pop_back();
  }
}

template <typename value_type>
void list<value_type>::operator=(list&& l) {
  while (l.head_ != nullptr) {
    push_back(l.head_->data);
    l.head_ = l.head_->pNext;
  }
  l.clear();
}

template <typename value_type>
void list<value_type>::operator=(const list& l) {
  clear();
  size_ = l.size_;
  Node<value_type>* tmp = l.head_;

  for (size_type i = 0; i < l.size_; ++i) {
    push_back(tmp->data);
    tmp = tmp->pNext;
  }
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  return head_->data;
}

template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  return tail_->data;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return iterator(head_);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(tail_);
}

template <typename value_type>
bool list<value_type>::empty() {
  return size_ == 0 ? true : false;
}

template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return size_;
}

// check this method
template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(Node<value_type>) /
          MAX_SIZE);
}

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    pop_back();
  }
  tail_ = nullptr;
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) noexcept {
  if (tail_ == nullptr) {
    head_ = new Node<value_type>(value, nullptr, nullptr);
    tail_ = head_;  // tail_ and head_ are point to one element
    size_ = 1;
  } else {
    Node<value_type>* current_ = tail_;
    current_->pNext = new Node<value_type>(value, nullptr, current_);
    tail_ = current_->pNext;
    ++size_;
  }
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw "EMPTY LIST";
  }
  if (size_ == 1) {
    delete tail_;
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    tail_ = tail_->pPrev;
    delete tail_->pNext;
    tail_->pNext = nullptr;
  }
  --size_;
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) noexcept {
  if (head_ == nullptr) {
    head_ = new Node<value_type>(value, nullptr, nullptr);
    tail_ = head_;
    size_ = 1;
  } else {
    Node<value_type>* current_ = head_;
    current_->pPrev = new Node<value_type>(value, current_, nullptr);
    head_ = current_->pPrev;
    ++size_;
  }
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (empty()) {
    throw "EMPTY LIST";
  }
  if (size_ == 1) {
    delete head_;
    tail_ = nullptr;
    head_ = nullptr;
  } else {
    head_ = head_->pNext;
    delete head_->pPrev;
    head_->pPrev = nullptr;
  }
  --size_;
}

template <typename value_type>
typename list<value_type>::reference list<value_type>::ListIterator::operator*()
    const {
  return ptr->data;
}

template <typename value_type>
typename list<value_type>::value_type*
list<value_type>::ListIterator::operator->() const {
  return &ptr->data;
}

template <typename value_type>
typename list<value_type>::ListIterator&
list<value_type>::ListIterator::operator++() {
  if (ptr->pNext == nullptr) {
    while (ptr->pPrev != nullptr) {
      ptr = ptr->pPrev;
    }
  } else {
    ptr = ptr->pNext;
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator++(int) {
  ListIterator tmp = *this;
  if (ptr->pNext == nullptr) {
    while (ptr->pPrev != nullptr) {
      ptr = ptr->pPrev;
    }
  } else {
    ptr = ptr->pNext;
  }
  return tmp;
}

template <typename value_type>
typename list<value_type>::ListIterator&
list<value_type>::ListIterator::operator--() {
  if (ptr->pPrev == nullptr) {
    while (ptr->pNext != nullptr) {
      ptr = ptr->pNext;
    }
  } else {
    ptr = ptr->pPrev;
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator--(int) {
  ListIterator tmp = *this;
  if (ptr->pPrev == nullptr) {
    while (ptr->pNext != nullptr) {
      ptr = ptr->pNext;
    }
  } else {
    ptr = ptr->pPrev;
  }
  return tmp;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator==(
    const ListIterator& other) const {
  return ptr == other.ptr;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator!=(
    const ListIterator& other) const {
  return ptr != other.ptr;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator>(
    const ListIterator& other) const {
  return ptr > other.ptr;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator>=(
    const ListIterator& other) const {
  return ptr >= other.ptr;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator<(
    const ListIterator& other) const {
  return ptr < other.ptr;
}

template <typename value_type>
bool list<value_type>::ListIterator::operator<=(
    const ListIterator& other) const {
  return ptr <= other.ptr;
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos == nullptr) {
    throw "ERROR";
  }
  if (pos.ptr->pPrev == nullptr) {
    pop_front();
  } else if (pos.ptr->pNext == nullptr) {
    pop_back();
  } else {
    Node<value_type>* prevNode = pos.ptr->pPrev;
    Node<value_type>* nextNode = pos.ptr->pNext;
    prevNode->pNext = nextNode;
    nextNode->pPrev = prevNode;
    delete pos.ptr;
    --size_;
  }
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = head_;
  } else if (pos == end()) {
    push_back(value);
    pos = tail_;
  } else {
    Node<value_type>* tmp = pos.ptr;
    Node<value_type>* clear = new Node<value_type>(value, nullptr, nullptr);
    clear->pNext = tmp;
    clear->pPrev = tmp->pPrev;
    tmp->pPrev->pNext = clear;
    tmp->pPrev = clear;
    ++size_;
    return iterator(clear);
  }
  return pos;
}

template <typename value_type>
void list<value_type>::swap(list& other) {
  list<value_type> tmp;
  size_type this_size = size_;
  size_type other_size = other.size_;
  for (size_type i = 0; i < this_size; i++) {
    tmp.push_back(head_->data);
    pop_front();
  }
  for (size_type i = 0; i < other_size; i++) {
    push_back(other.head_->data);
    other.pop_front();
  }
  for (size_type i = 0; i < this_size; i++) {
    other.push_back(tmp.head_->data);
    tmp.pop_front();
  }
}

template <typename value_type>
void list<value_type>::merge(list& other) {
  size_type common_size = size_ + other.size_;
  list<value_type> tmp;
  for (size_type i = 0; i < common_size; ++i) {
    if (empty() && !other.empty()) {
      tmp.push_back(other.head_->data);
      other.pop_front();
    } else if (!empty() && other.empty()) {
      tmp.push_back(head_->data);
      pop_front();
    } else if (head_->data > other.head_->data) {
      tmp.push_back(other.head_->data);
      other.pop_front();
    } else {
      tmp.push_back(head_->data);
      pop_front();
    }
  }
  for (size_t i = 0; i < common_size; ++i) {
    push_back(tmp.head_->data);
    tmp.pop_front();
  }
}

template <typename value_type>
typename list<value_type>::const_reference
list<value_type>::ListConstIterator::operator*() const {
  return const_ptr->data;
}

template <typename value_type>
typename list<value_type>::ListConstIterator&
list<value_type>::ListConstIterator::operator++() {
  if (const_ptr->pNext == nullptr) {
    while (const_ptr->pPrev != nullptr) {
      const_ptr = const_ptr->pPrev;
    }
  } else {
    const_ptr = const_ptr->pNext;
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::ListConstIterator
list<value_type>::ListConstIterator::operator++(int) {
  ListConstIterator tmp = *this;
  if (const_ptr->pNext == nullptr) {
    while (const_ptr->pPrev != nullptr) {
      const_ptr = const_ptr->pPrev;
    }
  } else {
    const_ptr = const_ptr->pNext;
  }
  return tmp;
}

template <typename value_type>
typename list<value_type>::ListConstIterator&
list<value_type>::ListConstIterator::operator--() {
  if (const_ptr->pPrev == nullptr) {
    while (const_ptr->pNext != nullptr) {
      const_ptr = const_ptr->pNext;
    }
  } else {
    const_ptr = const_ptr->pPrev;
  }
  return *this;
}

template <typename value_type>
typename list<value_type>::ListConstIterator
list<value_type>::ListConstIterator::operator--(int) {
  ListConstIterator tmp = *this;
  if (const_ptr->pPrev == nullptr) {
    while (const_ptr->pNext != nullptr) {
      const_ptr = const_ptr->pNext;
    }
  } else {
    const_ptr = const_ptr->pPrev;
  }
  return tmp;
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cbegin() {
  return const_iterator(head_);
}

template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::cend() {
  return const_iterator(tail_);
}

template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) {
  Node<value_type>* value = pos.const_ptr;
  if (!other.empty()) {
    if (!empty()) {
      if (value == tail_) {
        tail_->pNext = other.head_;
        other.head_->pPrev = tail_;
        tail_ = other.tail_;
        size_ = size_ + other.size_;
      } else if (pos.const_ptr == head_) {
        head_->pPrev = other.tail_;
        other.tail_->pNext = head_;
        head_ = other.head_;
        size_ = size_ + other.size_;
      } else {
        Node<value_type>* start_ = value->pPrev;
        Node<value_type>* end_ = value;
        start_->pNext = other.head_;
        end_->pPrev = other.tail_;
        other.head_->pPrev = start_;
        other.tail_->pNext = end_;
        size_ = size_ + other.size_;
      }
      other.head_ = nullptr;
      other.tail_ = nullptr;
      other.size_ = 0;
    } else {
      swap(other);
      size_ = size_ + other.size_;
    }
  }
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator+(size_type n) const {
  ListIterator iter_(*this);
  for (; n != 0; --n) ++iter_;
  return iter_;
}

template <typename value_type>
typename list<value_type>::ListIterator
list<value_type>::ListIterator::operator-(size_type n) const {
  ListIterator iter_(*this);
  for (; n != 0; --n) --iter_;
  return iter_;
}

template <typename value_type>
void list<value_type>::reverse() {
  list<value_type> tmp;
  size_type const this_size_ = size_;
  for (size_type i = 0; i < this_size_; ++i) {
    tmp.push_back(tail_->data);
    pop_back();
  }
  for (size_type i = 0; i < this_size_; ++i) {
    push_front(tmp.tail_->data);
    tmp.pop_back();
  }
}

template <typename value_type>
void list<value_type>::unique() {
  list<value_type>::iterator start_ = ++begin();
  size_type const common_size = size_;
  for (size_type i = 0; i < common_size - 1; ++i, ++start_) {
    if (*start_ == *(start_ - 1)) {
      erase(start_ - 1);
    }
  }
}

template <typename value_type>
void list<value_type>::sort() {
  const size_type common_size = size_;
  for (size_type i = 0; i < common_size; ++i) {
    list<value_type>::iterator first_ = begin();
    list<value_type>::iterator second_ = first_ + 1;
    for (size_type j = 0; j < common_size - i; ++j) {
      if (*first_ > *second_) {
        value_type key = *first_;
        *first_ = *second_;
        *second_ = key;
      }
      ++first_;
      ++second_;
    }
  }
}
};  // namespace s21
