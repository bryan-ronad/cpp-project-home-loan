#include <bits/stdc++.h>
#include "../models/Application.h"
#include "../models/User.h"

class ApplicationService {
  public:
    virtual Application createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING") = 0;
    virtual map<long int, Application> getApplications() = 0;
    virtual map<long int, Application> getFilteredApplications(string status) = 0;
    virtual void updateApplicationStatus(long int applicationID, string status) = 0;
};
