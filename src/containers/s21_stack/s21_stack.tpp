namespace s21 {

template <typename value_type>
stack<value_type>::stack(std::initializer_list<value_type> const& items)
    : head_(nullptr), size_(0) {
  for (const auto& item : items) {
    push(item);
  }
}

template <typename value_type>
stack<value_type>::stack(const stack& s) : head_(nullptr), size_(0) {
  Node<value_type>* reverse = s.head_;
  stack<value_type> tmp_reverse;
  for (size_type i = 0; i < s.size_; ++i) {
    tmp_reverse.push(reverse->data);
    reverse = reverse->pNext_;
  }
  for (size_type i = 0; i < s.size_; ++i) {
    push(tmp_reverse.head_->data);
    tmp_reverse.pop();
  }
}

template <typename value_type>
stack<value_type>::stack(stack&& s) : head_(s.head_), size_(s.size_) {
  s.head_ = nullptr;
  s.size_ = 0;
}

template <typename value_type>
stack<value_type>::~stack() {
  size_type this_size_ = size_;
  for (size_type i = 0; i < this_size_; ++i) {
    pop();
  }
}

template <typename value_type>
void stack<value_type>::operator=(stack&& s) {
  while (!empty()) {
    pop();
  }
  stack<value_type> reverse_tmp;
  while (!s.empty()) {
    reverse_tmp.push(s.head_->data);
    s.pop();
  }
  while (!reverse_tmp.empty()) {
    push(reverse_tmp.head_->data);
    reverse_tmp.pop();
  }
}

template <typename value_type>
void stack<value_type>::operator=(const stack& s) {
  while (!empty()) {
    pop();
  }
  Node<value_type>* reverse = s.head_;
  stack<value_type> tmp_reverse;
  for (size_type i = 0; i < s.size_; ++i) {
    tmp_reverse.push(reverse->data);
    reverse = reverse->pNext_;
  }
  for (size_type i = 0; i < s.size_; ++i) {
    push(tmp_reverse.head_->data);
    tmp_reverse.pop();
  }
}

template <typename value_type>
typename stack<value_type>::const_reference stack<value_type>::top() {
  return head_->data;
}

template <typename value_type>
typename stack<value_type>::size_type stack<value_type>::size() {
  return size_;
}

template <typename value_type>
bool stack<value_type>::empty() {
  return size_ == 0 ? true : false;
}

template <typename value_type>
void stack<value_type>::push(const_reference value) {
  if (size_ == 0) {
    head_ = new Node<value_type>(value, nullptr);
    size_ = 1;
  } else {
    head_ = new Node<value_type>(value, head_);
    ++size_;
  }
}

template <typename value_type>
void stack<value_type>::pop() {
  if (!empty()) {
    Node<value_type>* tmp = head_;
    head_ = head_->pNext_;
    delete tmp;
    --size_;
  } else {
    throw "ERROR";
  }
}

template <typename value_type>
void stack<value_type>::swap(stack& other) {
  stack<value_type> tmp = std::move(other);
  other = std::move(*this);
  *this = std::move(tmp);
}

}  // namespace s21