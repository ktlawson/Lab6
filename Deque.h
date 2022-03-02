//
// Created by Katelyn Lawson on 2/27/22.
//

#ifndef LAB6_DEQUE_H
#define LAB6_DEQUE_H
#include "DequeInterface.h"
#include "CircularArray.h"

template<typename T>
class Deque : public DequeInterface<T>{
public:
   CircularArray<T> circularArray;

   Deque(const size_t elems) : circularArray(elems) {
   };

   ~Deque() {
   }
   //Create a Deque template class derived from the DequeInterface class.
   //Use a dynamic array to contain the typename objects.
   //Use a default array size of 4 and resize as needed.
   /** Insert item at front of deque */
   virtual void push_front(const T& value) {
      // add value to front of array
      circularArray.push_front(value);
   }

   /** Insert item at rear of deque */
   virtual void push_back(const T& value) {
      circularArray.push_back(value);
   }

   /** Remove the front item of the deque */
   virtual void pop_front(void) {
      circularArray.pop_front();
   }

   /** Remove the rear item of the deque */
   virtual void pop_back(void) {
      circularArray.pop_back();
   }

   /** Return the front item of the deque (Do not remove) */
   virtual T& front(void) {
      circularArray.front();
   }

   /** Return the rear item of the deque (Do not remove) */
   virtual T& back(void) {
      circularArray.back();
   }

   /** Return the number of items in the deque */
   virtual size_t size(void) const {
      circularArray.size();
   }

   /** Return true if deque is empty */
   virtual bool empty(void) const {
      circularArray.empty();
   }

   /** Return item in deque at index (0 based) */
   virtual T& at(size_t index) {
      circularArray.at(index);
   }

   /** Return the deque items */
   virtual std::string toString(void) const {
      circularArray.toString();
   }

   friend ostream &operator<<(ostream &os, const Deque<T> &deque) {
      os << deque.toString();
      return os;
   }
};
#endif //LAB6_DEQUE_H
