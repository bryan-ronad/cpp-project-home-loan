#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
using namespace std;

/*
Application Form
*/
class Application
{
public:
  long int applicationID = rand();
  long int applicantID;
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
  string applicationStatus;
  friend ostream& operator<<(ostream &out, Application &a);
	friend istream& operator>>(istream &in, Application &a);

  public:
    /*
    Constructors
    */
    Application(long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
    {
      this->applicantID = applicantID;
      this->propertyName = propertyName;
      this->propertyCost = propertyCost;
      this->salary = salary;
      this->PAN = PAN;
      this->Aadhaar = Aadhaar;
      this->applicationStatus = applicationStatus;
    }
    Application(long int applicationID, long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
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
    long int getApplicationID(){
      return this->applicationID;
    }

    /*
    Setter functions
    */
    void setApplicationStatus(string status){
      this->applicationStatus = status;
    }
};

ostream& operator<<(ostream &out, Application &a)
{
  out<<a.applicationID<<" "<<a.applicantID<<" "<<a.applicationStatus<<" "<<a.propertyName<<" "<<a.propertyCost<<" "<<a.salary<<" "<<a.PAN<<" "<<a.Aadhaar<<"\n";
  return out;
}

istream& operator>>(istream &in, Application &a)
{
  in>>a.applicationID;
  in>>a.applicantID;
  in>>a.applicationStatus;
  in>>a.propertyName;
  in>>a.propertyCost;
  in>>a.salary;
  in>>a.PAN;
  in>>a.Aadhaar;
  return in;
}

#endif