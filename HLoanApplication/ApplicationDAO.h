#pragma once
#include "HLApplication.h"
#include <map>
using namespace std;

class ApplicationDAO {
	virtual HLApplication createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus) = 0;
	virtual long int getApplicationID(HLApplication application) = 0;
	virtual HLApplication getApplication(const long int appID) = 0;
	virtual map<long int, HLApplication> getApplications() = 0;
	virtual void approveApplication(HLApplication application) = 0;
	virtual void rejectApplication(HLApplication application) = 0;
	virtual void saveToFile(HLApplication application) = 0;
	virtual void updateApplicationStatus(HLApplication application, string status) = 0;
	virtual void deleteApplication(HLApplication application) = 0;
};
