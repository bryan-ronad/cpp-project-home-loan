#pragma once
#include "HLApplication.h"
#include <map>
using namespace std;

class ApplicationDAO {
	virtual HLApplication createApplication(long int applicantID, string propertyName, long int propertyCost, long int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING", long int amountPaid = 0, long int tenure = 5, long int tenure_remaining = 5, double emi = 0, float intrestRate = 8) = 0;
	virtual long int getApplicationID(HLApplication application) = 0;
	virtual HLApplication getApplication(const long int appID) = 0;
	virtual vector<map<string, string>> getApplications() = 0;
	virtual void approveApplication(HLApplication application) = 0;
	virtual void rejectApplication(HLApplication application) = 0;
	virtual void saveToFile(HLApplication application) = 0;
	virtual bool updateApplicationStatus(HLApplication application, string status) = 0;
};
