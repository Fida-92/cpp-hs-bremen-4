// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#include "list.h"
#include <cassert>
#include <iostream>
void TestEmpty();
void TestPush_front();
void TestPush_back();
void PrintTestResult(bool isTrue, std::string str);
void TestClear();
void TestPop_back();
void TestPop_front();
void TestFront();
void TestBack();
void TestListEnd();
void TestListBegin();
void TestEraseWithIterator();
void TestInsertWithIterator();
using namespace util;
int main() {

  TestPush_front();
  TestPush_back();
  TestPop_back();
  TestPop_front();
  TestFront();
  TestBack();
  TestClear();
  TestEmpty();
  TestInsertWithIterator();
  TestListBegin();
  TestListEnd();
  return 0;
}
void TestListEnd() {
  list<int> li;
  li.push_front(9);
  li.push_front(19);
  li.push_front(29);
  list<int>::iterator it(new Node<int>());
  assert(li.end().getM_pNode()->next == nullptr);
  PrintTestResult(!li.empty(), "list.end()");
}
void TestListBegin() {
  list<int> li;
  li.push_front(9);
  li.push_front(19);
  li.push_front(29);
  assert(li.begin().getM_pNode()->nodeData == 29);
  PrintTestResult(!li.empty(), "list.begin()");
}
void TestInsertWithIterator() {
  list<int> li;
  // li.push_back(19);
  // li.push_front(18);
  Node<int> *node = new Node<int>();
  node->nodeData = 5;
  list<int>::iterator it(node); // or &li.front() or &li.back()
  li.insert(it, 10);
  li.insert(it, 11);
  li.insert(it, 12);
  // std::cout << " List.size() " << li.size() << std::endl;
  list<int>::iterator itB = li.begin();
  list<int>::iterator itE = li.end();

  while (itB != itE) {
    std::cout << "iterator " << *itB << std::endl;
    itB++;
  }
  assert(li.size() == 4);
  PrintTestResult(!li.empty(), "it.insert()");
}
void TestEraseWithIterator() {}
void TestPop_front() {
  list<int> list;
  list.push_front(9);
  list.push_back(19);
  list.push_back(29);
  list.pop_front();
  Node<int> i = list.front();
  list.pop_front();
  assert(list.size() == 1 && i.nodeData == 19);
  PrintTestResult(!list.empty(), "pop_front()");
}

void TestBack() {
  list<int> list;
  list.push_front(9);
  list.push_back(19);
  list.push_back(29);
  list.pop_back();
  assert(list.size() == 2 && list.back().nodeData == 19);
  PrintTestResult(!list.empty(), "back()");
}

void TestFront() {
  list<int> list;
  list.push_front(9);
  list.push_back(19);
  list.push_back(29);
  assert(list.size() == 3 && list.front().nodeData == 9);
  PrintTestResult(!list.empty(), "front()");
}

void TestPop_back() {
  list<int> list;
  list.push_back(9);
  list.push_back(19);
  list.push_back(29);
  list.pop_back();
  assert(list.size() == 2);
  PrintTestResult(!list.empty(), "pop_back()");
}

void TestPush_back() {
  list<int> list;
  list.push_back(9);
  list.push_back(19);
  assert(list.size() == 2 && list.back().nodeData == 19);
  PrintTestResult(!list.empty(), "push_back()");
}

void TestClear() {
  list<int> list;
  list.push_front(9);
  list.push_front(19);
  list.clear();
  assert(list.size() == 0);
  PrintTestResult(list.empty(), "clear()");
}

void TestPush_front() {
  list<int> list;
  list.push_front(9);
  list.push_front(19);
  list.push_front(29);

  assert(list.size() == 3);
  PrintTestResult(!list.empty(), "push_front()");
  list.clear();
  assert(list.size() == 0);
}

void TestEmpty() {
  list<int> list;
  assert(list.empty());
  PrintTestResult(list.empty(), "empty()");
}
void PrintTestResult(bool isTrue, std::string str) {
  std::string info(isTrue ? "Successfully tested:     "
                          : "Failed test of:     ");
  std::cout << info << "\"" << str << "\"." << std::endl;
}
