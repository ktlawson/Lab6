//
// Created by Katelyn Lawson on 2/27/22.
//

#ifndef LAB6_CIRCULARARRAY_H
#define LAB6_CIRCULARARRAY_H
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// **********************************************************
// **********************************************************
template<typename T>
class CircularArray {
   T *arr = nullptr;
   T *head = nullptr;
   T *tail = nullptr;
   size_t cap;
   size_t numElements;

public:
   // **********************************************************
   CircularArray(const size_t elems) {
      cap = elems;
      arr = new T[elems];
      tail = head = arr ;
      numElements = 0;
   };

   // **********************************************************
   ~CircularArray() {
      delete [] arr;
   }

   // **********************************************************
   void resetArray() {
      tail = head = arr ;
   }

   // **********************************************************
   size_t size() {
      return numElements;
   }

   // **********************************************************
   T& at(size_t index) {
      T *current = head;
      if (index < size()) {
         for (unsigned int i = 0; i < index; i++) {
            if (current == &arr[cap]) {
               current = arr;
            } else {
               current += 1;
            }
         }
         return *current;
      } else {
         throw "Out of Bounds";
      }
   }

   // **********************************************************
   bool empty() {
      return size() == 0;
   }

   // **********************************************************
   const T* front() {
      if(numElements == 0) {
         return nullptr;
      } else {
         return head;
      }
   }

   // **********************************************************
   const T* back() {
      if(numElements == 0) {
         return nullptr;
      } else {
         return tail;
      }
   }

   // **********************************************************
   void push_back(const T &data) {
      if (numElements < cap) {
         if (numElements == 0) {
            head = tail = arr;
            *tail = data;
            numElements++;
         } else if (tail == &arr[cap-1]) {
            tail = arr;
            *tail = data;
            numElements++;
         } else {
            tail += 1;
            *tail = data;
            numElements++;
         }
      } else {
         doubleArraySize();
         push_back(data);
      }
   }

   // **********************************************************
   void push_front(const T &data) {
      if (numElements < cap) {
         if (numElements == 0) {
            head = tail = arr;
            *tail = data;
            numElements++;
         } else if (head == arr) {
            head = &arr[cap - 1];
            *head = data;
            numElements++;
         } else {
            head -= 1;
            *head = data;
            numElements++;
         }
      } else {
         doubleArraySize();
         push_front(data);
      }
   }

   // **********************************************************
   void pop_front() {
      if (numElements != 0) {
         if (head == &arr[cap - 1]) {
            head = arr;
         } else {
            head += 1;
         }
         numElements--;
         if(numElements == 0) {
            resetArray();
         }
      } else {
         cout << "Array is empty !" << endl;
      }
   }

   // **********************************************************
   void pop_back() {
      if (numElements != 0) {
         if (tail == arr) {
            tail == &arr[cap - 1];
         } else {
            tail -= 1;
         }
         numElements--;
      } else {
         cout << "Array is empty !" << endl;
      }
   }

   // **********************************************************
   void doubleArraySize() {
      T *newArray = new T[cap * 2];
      T *newTail = newArray;
      size_t tempSize = numElements;

      for (unsigned int i = 0; i < tempSize; i++) {
         newTail = newArray + i;
         *newTail = *head;
         pop_front();
      }

      delete [] arr;
      arr = newArray;
      cap *= 2;
      head = arr;
      tail = newTail;
      numElements = tempSize;
   }

   // **********************************************************
   string toString(void) const {
      ostringstream oss;

      T *iterator = head;
      for(unsigned int i = 0; i < numElements; i++) {
         oss << *(iterator) << " ";
         iterator += 1;
         if(iterator > &(arr[cap-1])) {
            iterator = arr;
         }
      }

      return oss.str();
   }

   // **********************************************************
   friend ostream &operator<<(ostream &os, const CircularArray<T> &circularArray) {
      os << circularArray.toString();
      return os;
   }
};

#endif //LAB6_CIRCULARARRAY_H
