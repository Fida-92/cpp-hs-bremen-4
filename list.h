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
  bool isLastNode;

  // Default ctor
  Node() {}
  ~Node() {}
  // getter and setter
  void setLastNode(bool isLast) { this->isLastNode = isLast; }
  bool getLastNode() { return this->isLastNode; }
};

template <typename T> class list {
private:
  Node<T> *m_end = new Node<T>();
  Node<T> *head, *tail;

public:
  // begin of the iterator class
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
      ++(*this); // (re-)using the pre-increment operator
      return tmp;
    }
    T &operator*() const { return m_pNode->nodeData; }
    T *operator->() const {
      T tmpData = m_pNode->nodeData;
      return &tmpData;
    }
  };
  // end of the iterator class

  list<T>() : head(m_end), tail(m_end) {
    m_end->setLastNode(true);
    head->prev = nullptr;
    m_end->next = nullptr;
  }
  Node<T> &front() { return *this->head; }
  Node<T> &back() const { return *this->tail; }
  bool empty() const { return this->head == m_end; }

  unsigned size() {
    unsigned counter = 0;
    Node<T> *tmp = head;
    while (head != m_end) {
      ++counter;
      head = head->next;
    }
    head = tmp;
    return counter;
  }
  void clear() {
    list<int>::iterator itB = this->begin();
    list<int>::iterator itE = this->end();
    while (itB != itE) {
      delete itB.m_pNode;
      ++itB;
    }
    this->head = m_end;
  }

  void pop_front() {
    if (head == m_end) {
      throw std::invalid_argument("list is empty");
      return; // nothing to "pop"
    } else if (this->size() == 1) {
      this->head = m_end;
      this->tail = m_end;
    } else {
      this->head = this->head->next;
      this->head->prev = nullptr;
    }
  }

  void pop_back() {
    if (head == m_end) {
      return; // nothing to "pop"
    } else if (this->size() == 1) {
      this->head = m_end;
      this->tail = m_end;
    } else {
      this->tail = this->tail->prev;
      this->tail->next = m_end;
    }
  }
  void push_front(const T &t) {
    Node<T> *newNode = createNode(t);
    if (head == m_end) {
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
    if (head == m_end) {
      handlePushesHeadIsNull(newNode);
    } else {
      newNode->prev = this->tail;
      this->tail->next = newNode;
      this->tail = newNode;
      m_end->prev = newNode;
      newNode->next = m_end;
    }
  }

  void handlePushesHeadIsNull(Node<T> *newNode) {
    this->head = newNode;
    this->head->prev = nullptr;
    this->head->next = m_end;
    this->tail = newNode;
    this->tail->next = m_end;
  }

  // iterator methods
  iterator begin() const { return iterator(head); }
  iterator end() const { return iterator(tail->next); }

  iterator insert(iterator &it, const T &t) {
    Node<T> *elemNode = createNode(t);
    elemNode->prev = it.m_pNode->prev;
    elemNode->next = it.m_pNode;
    if (it.m_pNode->prev != nullptr && it.m_pNode->prev != m_end) {
      it.m_pNode->prev->next = elemNode;
    } else {
      head = elemNode;
    }
    if (size() < 2) {
      tail = elemNode;
    }
    it.m_pNode->prev = elemNode;
    it.m_pNode = elemNode;
    return iterator(elemNode);
  }
  Node<T> *createNode(const T &t) {
    Node<T> *elemNode = new Node<T>();
    elemNode->nodeData = t;
    return elemNode;
  }
  iterator erase(iterator &it) {
    if (head == tail) {
      if (head == m_end) {
        return iterator(m_end);
      } else {
        delete it.m_pNode;
        it.m_pNode = m_end;
        head = m_end;
        tail = m_end;
        return iterator(m_end);
      }
    }
    if (it.m_pNode->prev != nullptr) {
      if (it.m_pNode->next != m_end) {
        it.m_pNode->prev->next = it.m_pNode->next;
        it.m_pNode->next->prev = it.m_pNode->prev;
        delete it.m_pNode;
        it.m_pNode = it.m_pNode->next;
      } else {
        it.m_pNode->prev->next = m_end;
        tail = it.m_pNode->prev;
        m_end->prev = tail;
        delete it.m_pNode;
        it.m_pNode = m_end;
      }
    } else {
      it.m_pNode->prev = nullptr;
      head = it.m_pNode->next;
      it.m_pNode = head;
    }
    return iterator(it.m_pNode);
  }
};
} // namespace util
#endif // LIST_H
