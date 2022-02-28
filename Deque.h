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
   CircularArray<T> circularArray(4);

   Deque() {}
   ~Deque() {}
   //Create a Deque template class derived from the DequeInterface class.
   //Use a dynamic array to contain the typename objects.
   //Use a default array size of 4 and resize as needed.
   /** Insert item at front of deque */
   virtual void push_front(const T& value) {

   }

   /** Insert item at rear of deque */
   virtual void push_back(const T& value) {

   }

   /** Remove the front item of the deque */
   virtual void pop_front(void) {

   }

   /** Remove the rear item of the deque */
   virtual void pop_back(void) {

   }

   /** Return the front item of the deque (Do not remove) */
   virtual T& front(void) {

   }

   /** Return the rear item of the deque (Do not remove) */
   virtual T& back(void) {

   }

   /** Return the number of items in the deque */
   virtual size_t size(void) const {

   }

   /** Return true if deque is empty */
   virtual bool empty(void) const {

   }

   /** Return item in deque at index (0 based) */
   virtual T& at(size_t index) {

   }

   /** Return the deque items */
   virtual std::string toString(void) const {

   }
};
#endif //LAB6_DEQUE_H
