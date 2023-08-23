#include <iostream>
#include <string>
using namespace std;

class ApplicationNotFoundException : public exception {
  public:
    string what(){
      return "Application not found!";
    }
};