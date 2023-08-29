#pragma once
#include <map>
#include "HLApplication.h"
#include "User.h"

class ApplicationService {
public:
    virtual map<string, string> createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING") = 0;
    virtual vector<map<string, string>> getApplications() = 0;
    virtual bool updateApplicationStatus(long int applicationID, string status) = 0;
};