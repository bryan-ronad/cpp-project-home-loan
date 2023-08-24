#pragma once
#include <bits/stdc++.h>
#include "../models/Application.h"
#include "Menu.cpp"
using namespace std;

class List {
  public:
    static void listApplications(map<long int, Application> applicationMap)
    {
      Menu::hr();
      map<long int, Application>::iterator it;
      for (it = applicationMap.begin(); it != applicationMap.end(); it++)
      {
      cout<<it->first<<": "<<it->second;
      }
      cout<<"\n";
    }
};