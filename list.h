// Author: Ahmadi, Fida
// MatrikelNummer: 50101292

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdexcept>
namespace util {
template <typename T> class Node {
public:
  // data type of element in node
  T nodeData;
  Node *prev;
  Node *next;
  bool last;

  // Default ctor
  Node() : prev(nullptr), next(nullptr) {}
  ~Node() {
    delete prev;
    delete next;
  }
  // getter and setter
  void setLast(bool last) { this->last = last; }
  bool gerLast() { return this->last; }
};

template <typename T> class list {
private:
  Node<T> *m_end = new Node<T>();
  Node<T> *head = m_end, *tail = m_end;

public:
  // Iterator
  class iterator {
    friend class list;
    Node<T> *m_pNode;

  public:
    Node<T> *getM_pNode() { return this->m_pNode; }
    iterator(Node<T> *pNode) : m_pNode(pNode) {}
    inline bool operator==(const iterator &it) const {
      return it.m_pNode == this->m_pNode;
    }
    inline bool operator!=(const iterator &it) const {
      return !(it.m_pNode == this->m_pNode);
    }
    // pre-increment
    iterator &operator++() {
      m_pNode = m_pNode->next;

      return *this;
    }
    // the int param. is to distinguish pre-increment from post-increment
    // post-increment
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this); // using the pre-increment operator
      return tmp;
    }
    T &operator*() const { return m_pNode->nodeData; }
    T *operator->() const {
      T tmpData = m_pNode->nodeData;
      return &tmpData;
    }
  };
  // end of iterator class

  list<T>() : head(nullptr), tail(nullptr) { m_end->setLast(true); }
  Node<T> &front() { return *this->head; }
  Node<T> &back() const { return *this->tail; }
  bool empty() const { return this->head == nullptr; }
  unsigned size() {
    unsigned counter = 0;
    Node<T> *tmp = head;
    while (head != nullptr) {
      ++counter;
      head = head->next;
    }
    head = tmp;
    return counter;
  }
  void clear() { this->head = nullptr; }

  void pop_front() {
    if (head == nullptr) {
      throw std::invalid_argument("list is empty");
      return; // nothing to "pop"
    } else if (this->size() == 1) {
      this->head = nullptr;
      this->tail = nullptr;
    } else {
      this->head = this->head->next;
      this->head->prev = nullptr;
    }
  }

  void pop_back() {
    if (head == nullptr) {
      return; // nothing to "pop"
    } else if (this->size() == 1) {
      this->head = nullptr;
      this->tail = nullptr;
    } else {
      this->tail = this->tail->prev;
      this->tail->next = nullptr;
    }
  }
  void push_front(const T &t) {
    Node<T> *newNode = createNode(t);
    if (head == nullptr) {
      handlePushesHeadIsNull(newNode);
    } else {
      newNode->next = this->head;
      newNode->prev = nullptr;
      this->head->prev = newNode;
      this->head = newNode;
    }
  }
  void push_back(const T &t) {
    Node<T> *newNode = createNode(t);
    if (head == nullptr) {
      handlePushesHeadIsNull(newNode);
    } else {
      newNode->prev = this->tail;
      this->tail->next = newNode;
      this->tail = newNode;
    }
  }

  void handlePushesHeadIsNull(Node<T> *newNode) {
    this->head = newNode;
    this->head->prev = nullptr;
    this->head->next = nullptr;
    this->tail = newNode;
  }

  // iterator methods
  iterator begin() const {
    // soll einen iterator zurückliefern der
    // auf das erste Element der Liste zeigt.
    return iterator(head);
  }
  iterator end() const { return iterator(tail); }

  iterator insert(iterator &it, const T &t) {
    Node<T> *elemNode = createNode(t);
    elemNode->prev = it.m_pNode->prev;
    elemNode->next = it.m_pNode;
    if (it.m_pNode->prev != nullptr) {
      it.m_pNode->prev->next = elemNode;
    } else {
      head = elemNode;
    }
    it.m_pNode->prev = elemNode;
    return iterator(elemNode);
  }
  Node<T> *createNode(const T &t) {
    Node<T> *elemNode = new Node<T>();
    elemNode->nodeData = t;
    return elemNode;
  }
  iterator erase(iterator &it) {
    if (it.m_pNode->prev != nullptr) {
      it.m_pNode->prev->next = it.m_pNode->next;
      it.m_pNode = it.m_pNode->next;
    } else {
      head = it.m_pNode->next;
      it.m_pNode = head;
    }
    if (it.m_pNode->next != nullptr) {
      it.m_pNode->next->prev = it.m_pNode->prev;
    } else {
      tail = it.m_pNode->next;
      it.m_pNode = tail;
    }
    return iterator(it.m_pNode);
  }
};

} // namespace util
#endif // LIST_H
