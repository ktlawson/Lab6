//
// Created by Katelyn Lawson on 2/27/22.
//

#ifndef LAB6_CAR_H
#define LAB6_CAR_H

#include <string>
using namespace std;

class Car {
public:
   unsigned int id;

   Car() {}

   Car(unsigned int id) : id(id) {}

   ~Car() {}

   bool operator== (const Car car){
      return id == car.id;
   }

   bool operator!= (const Car car){
      return id != car.id;
   }

   string toString(void) const {
      ostringstream oss;
      oss << id;
      return oss.str();
   }

   friend ostream &operator<<(ostream &os, const Car &myCar) {
      os << myCar.toString();
      return os;
   }
};

#endif //LAB6_CAR_H
