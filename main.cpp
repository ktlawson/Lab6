#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Car.h"
#include "CircularArray.h"
#include "Stack.h"

using namespace std;

int main(int argc, char *argv[]) {

   // Make sure we have the necessary input arguments
   if (argc != 3) {
      cout << "Please list input and output files in command line." << endl;
      cout << "For example: lab lab03_in_01.text lab03_out_01.text" << endl;
      return 0;
   }

   // Get file names
   string inputFileName = argv[1];
   string outputFileName = argv[2];

   // Open streams with file names
   ifstream in(inputFileName);
   ofstream out(outputFileName);

   // If streams fail, then explain and exit program
   if (!in) {
      cout << "Unable to open input file: " << inputFileName << endl;
      return 0;
   } else if (!out) {
      in.close();
      cout << "Unable to open output file: " << outputFileName << endl;
      return 0;
   }

   // **********************************************************
   // TEST CODE START
   CircularArray<Car> ca(4);
   Car car1(1);
   Car car2(2);
   Car car3(3);
   Car car4(4);
   Car car5(5);
   Car car6(6);

   ca.push_back(car1);
   ca.push_back(car2);
   cout << ca << endl;
   cout << "Num Cars: " << ca.size() << endl;
   cout << "Car: " << *ca.front() << endl;
   cout << "Car: " << *ca.back() << endl;
   ca.pop_back();
   cout << ca << endl;
   cout << "Num Cars: " << ca.size() << endl;
   ca.push_back(car3);
   ca.push_back(car4);
   ca.push_back(car5);
   cout << ca << endl;
   cout << "Num Cars: " << ca.size() << endl;
   ca.push_back(car6);
   cout << ca << endl;
   cout << "Num Cars: " << ca.size() << endl;
   ca.pop_front();
   ca.pop_front();
   ca.pop_front();
   cout << ca << endl;
   cout << "Num Cars: " << ca.size() << endl;

   cout << "Test";
   Stack<Car> carStack(4);
   // I haven't implemented all the stack methods yet.

   // TEST CODE END
   // **********************************************************


//   ca.push_back(car1);
//   cout << ca << endl;
//   ca.push_front(car2);
//   cout << ca << endl;
//   ca.push_back(car3);
//   cout << ca << endl;
//   ca.push_front(car4);
//   cout << ca << endl;
//   ca.push_back(car5);
//   cout << ca << endl;
//   ca.push_front(car6);
//   cout << ca << endl;

//   ca.push_back(car1);
//   ca.push_back(car2);
//   cout << ca << endl;
//   ca.push_back(car3);
//   ca.push_back(car4);
//   cout << ca << endl;
//   ca.push_back(car5);
//   cout << ca << endl;



   cout << "Test";

   // Open input and output files
   // process input strings
   for (string line; getline(in, line);) {
      // line equal to 1st line of text in file

      string item1;

      string errorString = "Not Found";
      // if the line size is 0, then move to next iteration of loop (next line)
      if (line.size() == 0) continue;
      // Write the 1st line to the output file
      //out << line;
      // break line into pieces and iterate
      istringstream iss(line);
      // get 1st item in line (command code)
      iss >> item1;
      // decide what to do with based on the command code
//      try {
//         if (item1 == "Expression:") {
//            expressionManager.setExpression(line.substr(item1.size() + 1));
//            out << endl << line << endl;
//
//         } else if (item1 == "Infix:"){
//            out << "Infix:" << expressionManager.infix() << endl;
//         } else if (item1 == "Postfix:"){
//            out << "Postfix:" << expressionManager.postfix() << endl;
//         } else if (item1 == "Prefix:"){
//            out << "Prefix:" << expressionManager.prefix() << endl;
//         } else if (item1 == "Value:"){
//            out << "Value: " << expressionManager.value() << endl;
//         } else {
//            out << endl;
//         }
//      } catch (const char *e) {
//         out << " " << e << endl;
//      } catch (const string *e) {
//         out << " " << e << endl;
//      } catch (...) {
//         out << " " << "Unknown Error!" << endl;
//      }
   }


// CLEAN UP EVERYTHING
   in.close();
   out.close();
   return 0;
}