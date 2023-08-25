#pragma once
#include "HLApplication.h"
#include <map>
#include <string>

using namespace std;

class UserService {
public:
    virtual map<string, string> login(long int applicantID, string password) = 0;
    virtual map<string, string> signup(string password,string first_name,string last_name,long int salary,string PAN,string Aadhar,bool is_admin,string age,string job_type) = 0;
    virtual bool logout() = 0;
    virtual bool checkEligibility(HLApplication) = 0;
};
