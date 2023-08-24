#include <iostream>
#include "../models/User.h"
using namespace std;

class UserDAO
{
    virtual User createUser(string password, string fname, string lname, long int salary, string PAN, string Aadhaar, bool is_admin) = 0;
    virtual long int getUserID(User user) = 0;
    virtual void saveToFile(User user) = 0;
    virtual void deleteUser(User user) = 0;
    virtual bool isAdmin(User user) = 0;
};