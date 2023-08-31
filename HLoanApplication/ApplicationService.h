#pragma once
#include <map>
#include "HLApplication.h"
#include "User.h"

class ApplicationService {
public:
    virtual map<string, string> createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING", long int amountPaid=0, long int tenure=5, long int tenure_remaining=5, float intrestRate=8) = 0;
    virtual vector<map<string, string>> getApplications() = 0;
    virtual bool updateApplicationStatus(long int applicationID, string status) = 0;
};