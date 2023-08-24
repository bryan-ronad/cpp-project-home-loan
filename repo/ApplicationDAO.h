#pragma once
#include <iostream>
#include "../models/Application.h"
using namespace std;

class ApplicationDAO {
  virtual Application createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus) = 0;
  virtual long int getApplicationID(Application application) = 0;
  virtual Application getApplication(const long int appID) = 0;
  virtual map<long int, Application> getApplications() = 0;
  virtual void approveApplication(Application application) = 0;  
  virtual void rejectApplication(Application application) = 0;  
  virtual void saveToFile(Application application) = 0;  
  virtual void updateApplicationStatus(Application application, string status) = 0;  
  virtual void deleteApplication(Application application) = 0;  
};