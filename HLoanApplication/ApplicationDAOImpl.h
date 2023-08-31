#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "ApplicationDAO.h"
#include "HLApplication.h"
#include "CalcServiceImpl.h"
using namespace std;

class ApplicationDAOImpl:public ApplicationDAO {
public:
    HLApplication createApplication(long int applicantID, string propertyName, long int propertyCost, long int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING", long int amountPaid=0, long int tenure=5, long int tenure_remaining=5, double emi=0, float intrestRate=8) {
        HLApplication tempApplication = HLApplication(applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus, amountPaid, tenure, tenure_remaining, emi, intrestRate);
        return tempApplication;
    }

    long int getApplicationID(HLApplication application)
    {
        return application.getApplicationID();
    }

    void approveApplication(HLApplication application)
    {
        application.setApplicationStatus("APPROVED");

    }

    void rejectApplication(HLApplication application)
    {
        application.setApplicationStatus("REJECTED");
    }

    void saveToFile(HLApplication application)
    {
        ofstream fout("applications.txt", ofstream::app);
        if (fout.is_open())
        {
            fout << application;
        }
        else
        {
            cerr << "Unable to open file for writing" << endl;
        }
        fout.close();
    }

    vector<map<string, string>> getApplications()
    {
        vector<map<string, string>> tempVec;


        ifstream input("applications.txt");
        if (input) {
            string line;
            string _application_id;
            string _applicant_id;
            string _status;
            string _property_name;
            string _loan_amt;
            string _salary;
            string _pan;
            string _aadhar;


            while (getline(input, line)) {
                map<string, string> tempMap;

                istringstream iss(line);
                iss >> _application_id;
                iss >> _applicant_id;
                iss >> _status;
                iss >> _property_name;
                iss >> _loan_amt;
                iss >> _salary;
                iss >> _pan;
                iss >> _aadhar;
                tempMap["ApplicationId"] = _application_id;
                tempMap["ApplicantId"] = _applicant_id;
                tempMap["Status"] = _status;
                tempMap["PropertyName"] = _property_name;
                tempMap["LoanAmount"] = _loan_amt;
                tempMap["Salary"] = _salary;
                tempMap["PAN"] = _pan;
                tempMap["Aadhar"] = _aadhar;





                tempVec.push_back(tempMap);
            }
        }
        return tempVec;
    };
    vector<map<string,string>> getApplicationsByApplicantId(string applicant_id)
    {
        vector<map<string,string>> tempvec;
        ifstream input("applications.txt");
        if (input) {
            string line;
            string _application_id;
            string _applicant_id;

            string _status;
            string _loan_amt;


            string _property_name;

            while (getline(input, line)) {

                istringstream iss(line);

                iss >> _application_id;

                iss >> _applicant_id;
                if (applicant_id == _applicant_id) {
                    iss >> _status;
                    iss >> _property_name;
                    iss >> _loan_amt;
                    map<string,string> tempMap;
                    tempMap["ApplicationId"] = _application_id;
                    tempMap["Status"] = _status;

                    tempMap["PropertyName"] = _property_name;
                    tempMap["LoanAmt"] = _loan_amt;


                  

                tempvec.push_back(tempMap);
                }
            }
        }
        return tempvec;
    };

    bool updatePayment(HLApplication application, long int amount) {
        map<long int, HLApplication> applicationMap = ApplicationDAOImpl::getApplicationsMap();
        // Find key and update in map
        map<long int, HLApplication>::iterator iter = applicationMap.find(application.getApplicationID());

        if (iter == applicationMap.end()) return false;

        HLApplication tempApplication = applicationMap[application.getApplicationID()];
        map<string, double> payment_info = getPaymentInfo(tempApplication);
        tempApplication.setRemainingAmt(payment_info["amountPaid"]+amount);
        tempApplication.setTenureRemaining(CalcServiceImpl::getEmitenure(payment_info["propertyCost"] - (payment_info["amountPaid"]+ amount), payment_info["intrestRate"] / 1200, payment_info["emi"]));

        // Find key and update in map
        if (iter == applicationMap.end()) throw exception();
        iter->second = tempApplication;


        // Truncate All Data first
        ofstream ofs;
        ofs.open("applications.txt", ofstream::out | ofstream::trunc);
        ofs.close();

        // Append All Data



        ofstream fout("applications.txt", ofstream::app);
        if (fout.is_open()) {
            for (iter = applicationMap.begin(); iter != applicationMap.end(); iter++) {
                fout << iter->second;
            }
        }
        else {
            cerr << "Unable to open file for writing" << endl;
        }
        fout.close();
        return true;
    }
    vector<map<string, string>> getApplicationsByApplicantIdApproved(string applicant_id)
    {
        vector<map<string, string>> tempvec;
        ifstream input("applications.txt");
        if (input) {
            string line;
            string _application_id;
            string _applicant_id;

            string _status;
            string _loan_amt;
            string _salary;
            string _PAN;
            string _Aadhar;



            string _property_name;
            string amountPaid ;

            string tenure;
            string tenure_remaining;

            string emi ;
            string intrestRate ;

            while (getline(input, line)) {

                istringstream iss(line);

                iss >> _application_id;

                iss >> _applicant_id;
                iss >> _status;
                if (applicant_id == _applicant_id && _status =="APPROVED") {
                    iss >> _property_name;
                    iss >> _loan_amt;
                    iss >> _salary;

                    iss >> _PAN;
                    iss >> _Aadhar;

                    iss >> amountPaid;
                    iss >> tenure;
                    iss >> tenure_remaining;
                    iss >> emi;
                    iss >> intrestRate;

                    map<string, string> tempMap;
                    tempMap["ApplicationId"] = _application_id;

                    tempMap["PropertyName"] = _property_name;
                    tempMap["LoanAmt"] = _loan_amt;

                    tempMap["amountPaid"] = amountPaid;
                    tempMap["tenure (in months)"] = tenure;
                    tempMap["tenure_remaining (in months)"] = tenure_remaining;
                    tempMap["emi"] = emi;
                    tempMap["intrestRate"] = intrestRate;




                    tempvec.push_back(tempMap);
                }
            }
        }
        return tempvec;
    };

    HLApplication getApplication(const long int appID) {
        map<long int, HLApplication> applicationMap = ApplicationDAOImpl::getApplicationsMap();
        return applicationMap[appID];
    }
    /*
    
    

    void deleteApplication(HLApplication application) {
        map<long int, HLApplication> applicationMap = ApplicationDAOImpl::getApplications();
        // Find key and delete in map
        map<long int, HLApplication>::iterator iter = applicationMap.find(application.getApplicationID());
        if (iter == applicationMap.end()) throw exception();
        applicationMap.erase(iter);

        // Truncate All Data first
        ofstream ofs;
        ofs.open("applications.txt", ofstream::out | ofstream::trunc);
        ofs.close();


        // Append All Data
        ofstream fout("applications.txt", ofstream::app);
        if (fout.is_open()) {
            for (iter = applicationMap.begin(); iter != applicationMap.end(); iter++) {
                fout << iter->second;
            }
        }
        else {
            cerr << "Unable to open file for writing" << endl;
        }
        fout.close();
    }

   
    */
    map<long int, HLApplication> getApplicationsMap()
    {
        HLApplication tempApp;
        map<long int, HLApplication> tempMap;
        ifstream input("applications.txt");
        if (input) {
            string line;
            while (getline(input, line)) {
                istringstream iss(line);
                iss >> tempApp;
                tempMap.insert(make_pair(tempApp.getApplicationID(), tempApp));
            }
        }
        return tempMap;
    };
    bool updateApplicationStatus(HLApplication application, string status) {
        map<long int, HLApplication> applicationMap = ApplicationDAOImpl::getApplicationsMap();
        // Find key and update in map
        map<long int, HLApplication>::iterator iter = applicationMap.find(application.getApplicationID());

        if (iter == applicationMap.end()) return false;
        
        HLApplication tempApplication = applicationMap[application.getApplicationID()];
        if (status == "APPROVED") {
            tempApplication.setApplicationStatus("APPROVED");
           // PaymentDAOImpl payimpl;
            // payimpl.createPayment(application.getApplicationID(),application.applicantID,apllication.pro);
        }
        else if (status == "REJECTED") {
            tempApplication.setApplicationStatus("REJECTED");
        }
        // Find key and update in map
        if (iter == applicationMap.end()) throw exception();
        iter->second = tempApplication;


        // Truncate All Data first
        ofstream ofs;
        ofs.open("applications.txt", ofstream::out | ofstream::trunc);
        ofs.close();

        // Append All Data
        
        
        
        ofstream fout("applications.txt", ofstream::app);
        if (fout.is_open()) {
            for (iter = applicationMap.begin(); iter != applicationMap.end(); iter++) {
                fout << iter->second;
            }
        }
        else {
            cerr << "Unable to open file for writing" << endl;
        }
        fout.close();
        return true;

    }
    
};