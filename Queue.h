//
// Created by Katelyn Lawson on 3/1/22.
//

#ifndef LAB6_QUEUE_H
#define LAB6_QUEUE_H

#include <iostream>
#include <sstream>
#include "Deque.h"
using namespace std;

template<typename T>
class Queue {
   Deque<T> deque;

public:
   Queue(const size_t elems) : deque(elems) {
   }

   ~Queue() {
   }

   virtual void push(const T& data) {
      deque.push_back(data);
   }

   virtual void pop() {
      deque.pop_front();
   }

   virtual  T& at(const size_t index) {
      return deque.at(index);;
   }

   virtual T& top() {
      return deque.front();
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
   friend ostream &operator<<(ostream &os, const Queue<T> &queue) {
      os << queue.toString();
      return os;
   }
};
#endif //LAB6_QUEUE_H
