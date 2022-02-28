//
// Created by Katelyn Lawson on 2/27/22.
//

#ifndef LAB6_CIRCULARARRAY_H
#define LAB6_CIRCULARARRAY_H
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
class CircularArray {
public:
   CircularArray(const size_t elems) {
      cap = elems;
      arr = new T[elems];
      tail = head = arr ;
      size = 0;
   };

   int enqueue(const T &data) {
      if (size < cap) {
         if (size == 0) {
            head = tail = arr;
            *tail = data;
            size++;
            return 0;
         }

         if (tail == &arr[cap]) {
            tail = arr;
            *tail = data;
            size++;
         } else {
            tail = tail + 1;
            *tail = data;
            size++;
         }
         return 0;
      } else {
         //increase array size and add it
         T *newArray = new T[cap * 2];
         T *newTail = newArray;
         size_t tempSize = size;

         for (unsigned int i = 0; i < tempSize; i++) {
            newTail = newArray + i;
            newTail = dequeue();
         }

         delete [] arr;
         arr = newArray;
         cap *= 2;
         head = arr;
         tail = newTail;
         enqueue(data);
      }
   }

   T *dequeue() {
      if (size != 0) {
         // return value will equal head
         auto ret = head;

         if (head == &arr[cap]) {
            head = arr;
         } else {
            head = head + 1;
         }

         size--;
         return ret;
      } else {
         cout << "Array is empty !" << endl;
         return nullptr;
      }
   }

   size_t getSize() {
      return size;
   }

   ~CircularArray() {
      delete [] arr;
   }

private:
   T *arr = nullptr;
   T *head = nullptr;
   T *tail = nullptr;
   size_t cap;
   size_t size;
};
#endif //LAB6_CIRCULARARRAY_H
