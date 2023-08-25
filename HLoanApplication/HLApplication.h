#pragma once
#ifndef HLApplication_H
#define HLApplication_H

#include <iostream>
using namespace std;

/*
Application Form
*/
class HLApplication {
public:
    long int applicationID = rand();
    long int applicantID;
    string propertyName;
    long int propertyCost;
    long int salary;
    string PAN;
    string Aadhaar;
    string applicationStatus;
    friend ostream& operator<<(ostream& out, HLApplication& a);
    friend istream& operator>>(istream& in, HLApplication& a);

public:
    /*
    Constructors
    */
    HLApplication(long int applicantID = 0, string propertyName = "",long int propertyCost = 0, long int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
    {
        this->applicantID = applicantID;
        this->propertyName = propertyName;
        this->propertyCost = propertyCost;
        this->salary = salary;
        this->PAN = PAN;
        this->Aadhaar = Aadhaar;
        this->applicationStatus = applicationStatus;
    }
    HLApplication(long int applicationID, long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
    {
        this->applicationID = applicationID;
        this->applicantID = applicantID;
        this->propertyName = propertyName;
        this->propertyCost = propertyCost;
        this->salary = salary;
        this->PAN = PAN;
        this->Aadhaar = Aadhaar;
        this->applicationStatus = applicationStatus;
    }

    /*
    Getter functions
    */
    long int getApplicationID() {
        return this->applicationID;
    }
    string getApplicationStatus() {
        return this->applicationStatus;
    }
    long int getApplicantID() {
        return this->applicantID;
    }
    /*
    Setter functions
    */
    void setApplicationStatus(string status) {
        this->applicationStatus = status;
    }
};

ostream& operator<<(ostream& out, HLApplication& a)
{
    out << a.applicationID << " " << a.applicantID << " " << a.applicationStatus << " " << a.propertyName << " " << a.propertyCost << " " << a.salary << " " << a.PAN << " " << a.Aadhaar << "\n";
    return out;
}

istream& operator>>(istream& in, HLApplication& a)
{
    in >> a.applicationID;
    in >> a.applicantID;
    in >> a.applicationStatus;
    in >> a.propertyName;
    in >> a.propertyCost;
    in >> a.salary;
    in >> a.PAN;
    in >> a.Aadhaar;
    return in;
}

#endif
