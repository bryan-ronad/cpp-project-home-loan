#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class UserDAO
{
    virtual User  createUser(string password, string fname, string lname, long int salary, string PAN, string Aadhaar, bool is_admin) const = 0 ;
    virtual long int getUserID(User user) const = 0;
    virtual void saveToFile(User user)const = 0;
    virtual void deleteUser(User user) const = 0;
    virtual bool isAdmin(User user) const = 0;
};