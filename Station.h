//
// Created by Katelyn Lawson on 3/1/22.
//

#ifndef LAB6_STATION_H
#define LAB6_STATION_H


#include <iostream>
#include <sstream>
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

template<typename T>
class Station {
   const int DEFAULT_DEQUE_SIZE = 4;
public:
   Station() : train(DEFAULT_DEQUE_SIZE), stack(DEFAULT_DEQUE_SIZE), queue(DEFAULT_DEQUE_SIZE) {}
   ~Station() {}

   Vector<T> train;
   Stack<T> stack;
   Queue<T> queue;
   T turnTableCar;
   bool empty = true;

   string addCar(const T& car) {
      string result;
      if (empty) {
         turnTableCar = car;
         empty = false;
         result = "OK";
      } else {
         result = "Turntable occupied!";
      }
      return result;
   }

   string removeCar() {
      //A train car is removed from the turntable and pushed into the train vector.
      string result;
      if (empty) {
         result = "Turntable empty!";
      } else {
         train.push_back(turnTableCar);
         empty = true;
         result = "OK";
      }
      return result;
   }

   string topCar() {
      //Display the current train car on station turntable,
      //Display the train car at head of Queue roundhouse.
      //Display the train car at head of Stack roundhouse.

      string result;
      if (empty) {
         result = "Turntable empty!";
      } else {
         result = turnTableCar.toString();
      }
      return result;
   }

   string sizeTrain() {

   }

   string addStack() {

   }

   string removeStack() {

   }

   string topStack() {

   }

   string sizeStack() {

   }

   string addQueue() {

   }

   string removeQueue() {

   }

   string topQueue() {

   }

   string sizeQueue() {

   }

   string find(T) {

   }

   string toString() const{

   }

   friend ostream &operator<<(ostream &os, const Station<T> &station) {
      os << station.toString();
      return os;
   }

};
#endif //LAB6_STATION_H
