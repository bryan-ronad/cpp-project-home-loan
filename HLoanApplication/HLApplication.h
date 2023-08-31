#pragma once
#ifndef HLApplication_H
#define HLApplication_H
#include <iomanip>

#include <iostream>
using namespace std;

/*
Application Form
*/
class HLApplication {

    long int applicationID = rand();
    long int applicantID;
    string propertyName;
    long int propertyCost;
    long int salary;
    string PAN;
    string Aadhaar;
    string applicationStatus;
    long int amountPaid = 0;
    long int tenure;
    long int tenure_remaining;
    double emi = 0;
    float intrestRate = 0;

    friend ostream& operator<<(ostream& out, HLApplication& a);
    friend istream& operator>>(istream& in, HLApplication& a);
    friend map<string, double> getPaymentInfo(HLApplication app);

public:
    /*
    Constructors
    */
    HLApplication(long int applicantID = 0, string propertyName = "",long int propertyCost = 0, long int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING", long int amountPaid=0, long int tenure=0, long int tenure_remaining=0, double emi=0, float intrestRate=0)
    {
        this->applicantID = applicantID;
        this->propertyName = propertyName;
        this->propertyCost = propertyCost;
        this->salary = salary;
        this->PAN = PAN;
        this->Aadhaar = Aadhaar;
        this->applicationStatus = applicationStatus;
        this->amountPaid = amountPaid;
        this->tenure = tenure*12;
        this->tenure_remaining = tenure_remaining*12;
        this->emi = emi;
        this->intrestRate = intrestRate;
    }
    HLApplication(long int applicationID, long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING", long int amountPaid=0, long int tenure=0, long int tenure_remaining=0, double emi=0, float intrestRate=0)
    {
        this->applicationID = applicationID;
        this->applicantID = applicantID;
        this->propertyName = propertyName;
        this->propertyCost = propertyCost;
        this->salary = salary;
        this->PAN = PAN;
        this->Aadhaar = Aadhaar;
        this->applicationStatus = applicationStatus;
        this->amountPaid = amountPaid;
        this->tenure = tenure;
        this->tenure_remaining = tenure_remaining;
        this->emi = emi;
        this->intrestRate = intrestRate;
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
    void setRemainingAmt(long int amount) {
        this->amountPaid = amount;
    }
    void setTenureRemaining(long int tenure_remain) {
        this->tenure_remaining = tenure_remain;
    }
};
map<string, double> getPaymentInfo(HLApplication app) {
    map<string, double> response;
    response["emi"] = app.emi;
    response["amountPaid"] = app.amountPaid;
    response["tenure"] = app.tenure;
    response["tenure_remaining"] = app.tenure_remaining;
    response["intrestRate"] = app.intrestRate;
    response["propertyCost"] = app.propertyCost;
    return response;
}

ostream& operator<<(ostream& out, HLApplication& a)
{
    out << fixed << showpoint;
    out << setprecision(4);
    out <<a.applicationID << " " << a.applicantID << " " << a.applicationStatus << " " << a.propertyName << " " << a.propertyCost << " " << a.salary << " " << a.PAN << " " << a.Aadhaar << " " << a.amountPaid << " " << a.tenure << " " << a.tenure_remaining << " " << a.emi << " " << a.intrestRate << "\n";
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
    in >> a.amountPaid;
    in >> a.tenure;
    in >> a.tenure_remaining;
    in >> a.emi;
    in >> a.intrestRate;
    return in;
}

#endif
