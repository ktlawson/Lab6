//
// Created by Todd Lawson on 2/28/22.
//

#ifndef LAB6_STACK_H
#define LAB6_STACK_H

#include <iostream>
#include <sstream>
#include "Deque.h"
using namespace std;

template<typename T>
class Stack {
   Deque<T> deque;

public:
   Stack(const size_t elems) : deque(elems) {
   }

   ~Stack() {
   }

   virtual void push(const T& data) {
      deque.push_back(data);
   }

   virtual void pop() {
      deque.pop_back();
   }

   virtual  T& at(const size_t index) {
      return deque.at(index);;
   }

   virtual T& top() {
      return deque.back();
   }

   virtual size_t size() {
      return deque.size();
   }

   // **********************************************************
   string toString(void) const {
      ostringstream oss;
      oss << deque;
      return oss.str();
   }

   // **********************************************************
   friend ostream &operator<<(ostream &os, const Stack<T> &stack) {
      os << stack.toString();
      return os;
   }
};

#endif //LAB6_STACK_H
