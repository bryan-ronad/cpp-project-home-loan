#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <random>
using namespace std;

class User
{
public:
    long int applicantID = 0;
    string first_name;
    string last_name;
    string password;
    long int salary;
    string PAN;
    string Aadhaar;
    bool is_admin = false;
    friend ostream &operator<<(ostream &out, User &u);
    friend istream &operator>>(istream &in, User &u);

    User(string password = "", string fname = "", string lname = "", long int salary = 0, string PAN = "", string Aadhaar = "", bool is_admin = false)
    {
        if (password != "")
        {
            this->applicantID = rand();
            this->password = password;
            this->first_name = fname;
            this->last_name = lname;
            this->salary = salary;
            this->PAN = PAN;
            this->Aadhaar = Aadhaar;
            this->is_admin = is_admin;
        }
    }
    User(long int _applicantId, string password, string fname, string lname, long int salary, string PAN, string Aadhaar, bool is_admin)
    {
        this->applicantID = _applicantId;
        this->password = password;
        this->first_name = fname;
        this->last_name = lname;
        this->salary = salary;
        this->PAN = PAN;
        this->Aadhaar = Aadhaar;
        this->is_admin = is_admin;
    }
    long int getUserID()
    {
        return this->applicantID;
    }
};
ostream &operator<<(ostream &out, User &u)
{
    out << u.applicantID << " " << u.password << " " << u.first_name << " " << u.last_name << " " << u.salary << " " << u.PAN << " " << u.Aadhaar << " " << u.is_admin << "\n";
    return out;
}

istream &operator>>(istream &in, User &u)
{
    in >> u.applicantID;
    in >> u.password;
    in >> u.first_name;
    in >> u.last_name;
    in >> u.salary;
    in >> u.PAN;
    in >> u.Aadhaar;
    in >> u.is_admin;

    return in;
}
#endif
