#include <bits/stdc++.h>
#include "../models/Application.h"
#include "ApplicationService.h"
#include "../repo/ApplicationDaoImpl.h"

class ApplicationServiceImpl : public ApplicationService {
  private:
    ApplicationDAOImpl applicationDaoObj;
  public:
    ApplicationServiceImpl(ApplicationDAOImpl applicationDaoObj){
      this->applicationDaoObj = applicationDaoObj;
    }

    virtual Application createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING")
    {
      Application createdApp = this->applicationDaoObj.createApplication(applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus);
      applicationDaoObj.saveToFile(createdApp);
      return createdApp;
    } 

    virtual map<long int, Application> getApplications()
    {
      return this->applicationDaoObj.getApplications();
    }

    virtual map<long int, Application> getFilteredApplications(string status="PENDING")
    {
      map<long int, Application> applicationMap = this->getApplications();
      // Filtering applications based on status
      auto iterator = applicationMap.begin();
      while(iterator!=applicationMap.end())
      {
        if(iterator->second.getApplicationStatus()!=status)
        {
          applicationMap.erase(iterator++);
        } else {
          ++iterator;
        }
      }
      return applicationMap;
    }

    void updateApplicationStatus(long int applicationID, string status="APPROVED")
    {
      Application applicationToUpdate = this->applicationDaoObj.getApplication(applicationID);
      return this->applicationDaoObj.updateApplicationStatus(applicationToUpdate, status);
    }
};