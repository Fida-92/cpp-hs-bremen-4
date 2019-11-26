// Author: Ahmadi, Fida
// MatrikelNummer: 50101292
#include <iostream>
#include "list.h"
#include <cassert>
void TestEmpty();
void TestPush_front();
void TestPush_back();
void PrintTestResult(bool isTrue, std::string str);
void TestClear();
void TestPop_back();
void TestPop_front();
void TestFront();
void TestBack();
void TestBegin();
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
    TestBegin();
    return 0;
}
//class Test{
//public:
//    int nummer;
//    Test(int nummer):nummer(nummer){

//    }
//    void sysout(){
//        std::cout<< this->nummer<< std::endl;
//    }
//};
void TestBegin(){
    list<int> li;
    li.push_front(9);
    li.push_front(19);
    li.push_front(29);
    // Node<int> *node = new Node<int>();
    list<int>::iterator it(new Node<int>());
}
void TestInsertWithIterator(){
    list<int> li;
    li.push_back(19);
    li.push_front(18);
    Node<int> *node = new Node<int>();
    node->nodeData=5;
    list<int>::iterator it(&li.front());//&li.front()
    it = li.insert(it,10);
    it = li.insert(it,11);
    it = li.insert(it,12);
    it = li.insert(it,13);
     it = li.erase(it);
    std::cout << " vw "<<li.size()<< it.getM_pNode()->nodeData <<std::endl;
    list<int>::iterator itB = li.begin();
    list<int>::iterator itE = li.end();


    std::cout << li.begin().getM_pNode()->nodeData <<std::endl;
    std::cout << li.end().getM_pNode()->nodeData <<std::endl;

    while(itB != itE) {
        std::cout << "while-loop "<< *it <<std::endl;
        it++;
    }

    assert(4==4);
    // PrintTestResult(!li.empty(),"it.insert()");
    //delete node;

}
void TestEraseWithIterator(){

}
void TestPop_front(){
    list<int> list;
    list.push_front(9);
    list.push_back(19);
    list.push_back(29);
    list.pop_front();
    Node<int> i = list.front();
    list.pop_front();
    assert(list.size() == 1 && i.nodeData == 19);
    PrintTestResult(!list.empty(),"pop_front()");
}

void TestBack(){
    list<int> list;
    list.push_front(9);
    list.push_back(19);
    list.push_back(29);
    list.pop_back();
    assert(list.size() == 2 && list.back().nodeData == 19);
    PrintTestResult(!list.empty(),"back()");
}

void TestFront(){
    list<int> list;
    list.push_front(9);
    list.push_back(19);
    list.push_back(29);
    assert(list.size() == 3 && list.front().nodeData == 9);
    PrintTestResult(!list.empty(),"front()");
}

void TestPop_back(){
    list<int> list;
    list.push_back(9);
    list.push_back(19);
    list.push_back(29);
    list.pop_back();
    assert(list.size() == 2);
    PrintTestResult(!list.empty(),"pop_back()");
}

void TestPush_back(){
    list<int> list;
    list.push_back(9);
    list.push_back(19);
    assert(list.size() == 2 && list.back().nodeData == 19);
    PrintTestResult(!list.empty(),"push_back()");
}

void TestClear(){
    list<int> list;
    list.push_front(9);
    list.push_front(19);
    list.clear();
    assert(list.size() == 0);
    PrintTestResult(list.empty(),"clear()");
}

void TestPush_front(){
    list<int> list;
    list.push_front(9);
    list.push_front(19);
    list.push_front(29);

    assert(list.size() == 3);
    PrintTestResult(!list.empty(),"push_front()");
    list.clear();
    assert(list.size() == 0);
}

void TestEmpty(){
    list<int> list;
    assert(list.empty());
    PrintTestResult(list.empty(),"empty()");
}
void PrintTestResult(bool isTrue, std::string str){
    std::string info(isTrue ? "Successfully tested:     ": "Failed test of:     ");
    std::cout<<info<<"\""<< str <<"\"."<<std::endl;
}
