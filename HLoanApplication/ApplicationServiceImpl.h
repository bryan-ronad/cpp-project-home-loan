#pragma once
#include "HLApplication.h"
#include "ApplicationService.h"
#include "CalcServiceImpl.h"
#include "ApplicationDaoImpl.h"

class ApplicationServiceImpl:public ApplicationService {
private:
    ApplicationDAOImpl applicationDaoObj;
public:
    ApplicationServiceImpl(ApplicationDAOImpl _applicationDaoObj) {
        this->applicationDaoObj = _applicationDaoObj;
    }

    map<string, string> createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING", long int amountPaid=0, long int tenure=5, long int tenure_remaining=5, float intrestRate=8)
    {
        double emi = CalcServiceImpl::emiCalc(propertyCost, intrestRate, tenure);
        HLApplication createdApp = this->applicationDaoObj.createApplication(applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus, amountPaid, tenure, tenure_remaining, emi, intrestRate);
        applicationDaoObj.saveToFile(createdApp);
        map<string, string> response;
        response["status_code"] = "200";
        response["status_msg"] = "Successfully Created Loan Application";
        return response;
    }

    /*
     virtual map<long int, HLApplication> getFilteredApplications(string status = "PENDING")
    {
        map<long int, HLApplication> applicationMap = this->getApplications();
        // Filtering applications based on status
        auto iterator = applicationMap.begin();
        while (iterator != applicationMap.end())
        {
            if (iterator->second.getApplicationStatus() != status)
            {
                applicationMap.erase(iterator++);
            }
            else {
                ++iterator;
            }
        }
        return applicationMap;
    }

   
    */
    bool updateApplicationStatus(long int applicationID, string status = "APPROVED")
    {
        HLApplication applicationToUpdate = this->applicationDaoObj.getApplication(applicationID);
        return this->applicationDaoObj.updateApplicationStatus(applicationToUpdate, status);
    }
    virtual vector<map<string, string>> getApplications()
    {
        return this->applicationDaoObj.getApplications();
    }

    virtual vector<map<string,string>> getApplicationsByApplicantId(string applicant_id) {
        return this->applicationDaoObj.getApplicationsByApplicantId(applicant_id);
    }
    virtual vector<map<string, string>> getApplicationsByApplicantIdApproved(string applicant_id) {
        return this->applicationDaoObj.getApplicationsByApplicantIdApproved(applicant_id);
    }
    bool updatePayment(long int applicationID, long int amount )
    {
        HLApplication applicationToUpdate = this->applicationDaoObj.getApplication(applicationID);
        return this->applicationDaoObj.updatePayment(applicationToUpdate, amount);
    }


    
};