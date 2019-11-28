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
  TestEmpty();
  TestClear();
  TestListBegin();
  TestListEnd();
  TestInsertWithIterator();
  TestEraseWithIterator();
  return 0;
}
void TestListEnd() {
  list<int> li;
  li.push_front(9);
  li.push_front(19);
  li.push_front(29);
  list<int>::iterator it(new Node<int>());
  assert(li.back().next->getLastNode() == true);
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
  li.push_front(12);
  li.push_front(11);
  list<int>::iterator it(&li.front()); // e.g.
  li.push_front(7);
  li.push_front(6);
  li.insert(it, 10);
  li.insert(it, 9);
  li.insert(it, 8);
  list<int>::iterator itB = li.begin();
  list<int>::iterator itE = li.end();
  std::cout << "Testing insert() ..." << std::endl;
  std::cout << "     expected values      6, 7, 8, 9, 10, 11, 12 \n "
               "    actual values        ";
  unsigned counter = 0;
  while (itB != itE) {
    std::cout << *itB << ", ";
    ++itB;
    ++counter;
  }
  std::cout << std::endl;
  assert(li.size() == counter);
  PrintTestResult(!li.empty(), "list.insert()");
}
void TestEraseWithIterator() {
  list<int> li;
  li.push_front(39);
  li.push_front(29);
  list<int>::iterator it(&li.front());
  li.push_front(19);
  li.push_front(9);
  li.erase(it);
  li.erase(it);
  assert(li.size() == 2);
  PrintTestResult((li.size() == 2), "list.erase()");
}
void TestPop_front() {
  list<int> list;
  try {
    list.pop_front();
  } catch (...) {
    PrintTestResult(1, "pop_front() with an empty list");
  }
  list.push_front(9);
  list.push_front(19);
  list.push_front(29);
  list.pop_front();
  assert(list.size() == 2);
  PrintTestResult(!list.empty(), "pop_front() with a non-empty list");
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
