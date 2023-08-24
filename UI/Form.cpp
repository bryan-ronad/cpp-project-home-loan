#pragma once
#include <bits/stdc++.h>
#include "Menu.cpp"
using namespace std;

struct appFormStruct {
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
};

class Form {
  public:
    static struct appFormStruct applicationForm()
    { 
      appFormStruct appFormInput;
      Menu::hr();
      cout<<"Enter property name: ", cin>>appFormInput.propertyName;
      cout<<"Enter property cost: ", cin>>appFormInput.propertyCost;
      cout<<"Enter salary: ", cin>>appFormInput.salary;
      cout<<"Enter PAN: ", cin>>appFormInput.PAN;
      cout<<"Enter Aadhaar: ", cin>>appFormInput.Aadhaar;
      return appFormInput;

    }
};