#pragma once
#include <map>
#include "HLApplication.h"
#include "User.h"

class ApplicationService {
public:
    virtual HLApplication createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING") = 0;
    virtual map<long int, HLApplication> getApplications() = 0;
    virtual map<long int, HLApplication> getFilteredApplications(string status) = 0;
    virtual void updateApplicationStatus(long int applicationID, string status) = 0;
};