#pragma once
#include <bits/stdc++.h>
using namespace std;

class Menu {
  public:
    static void hr(int n=50){
      for(int i=0; i<=n; i++)
      {
        cout<<"-";
      }
      cout<<"\n";
    }

    static void mainMenu(){
      hr();
      cout<<"Choose an action to perform\n1. Create application\nChoice: ";
    }

    static void adminMainMenu(){
      hr();
      cout<<"Choose a menu to access\n1. Admin Menu\n2. Non-Admin Menu\nChoice: ";
    }

    static void adminFunctionalityMenu(){
      hr();
      cout<<"Choose an action to perforn\n1. List all applications\n2. List pending applications\nChoice: ";
    }

    static void adminApplicationMenu(){
      hr();
      cout<<"Choose an action to perform\n1. Approve application\n2. Reject application\n3. Check eligibility\nChoice: ";
    }
};