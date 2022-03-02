//
// Created by Katelyn Lawson on 3/1/22.
//

#ifndef LAB6_VECTOR_H
#define LAB6_VECTOR_H

#include <iostream>
#include <sstream>
#include "Deque.h"
using namespace std;

template<typename T>
class Vector {
   Deque<T> deque;

public:
   Vector(const size_t elems) : deque(elems) {
   }

   ~Vector() {
   }

   virtual void push_back(const T& data) {
      deque.push_back(data);
   }

   virtual void pop_back() {
      deque.pop_back();
   }

   virtual  T& at(const size_t index) {
      return deque.at(index);;
   }

   virtual T& back() {
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
   friend ostream &operator<<(ostream &os, const Vector<T> &vector) {
      os << vector.toString();
      return os;
   }

};

#endif //LAB6_VECTOR_H
