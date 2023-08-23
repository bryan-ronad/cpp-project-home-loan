#include <bits/stdc++.h>
#include <filesystem>
using namespace std;

/*
Application Form
*/
class Application
{

private:
  long int applicationID = rand();
  long int applicantID;
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
  string applicationStatus;

public:
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

  void printDetails()
  {
    cout << "Application ID: " << this->applicationID << endl;
    cout << "applicantID: " << this->applicantID << endl;
    cout << "propertyName: " << this->propertyName << endl;
    cout << "propertyCost: " << this->propertyCost << endl;
    cout << "salary: " << this->salary << endl;
    cout << "PAN: " << this->PAN << endl;
    cout << "Aadhaar: " << this->Aadhaar << endl;
    cout << "applicationStatus: " << this->applicationStatus << endl;
    cout << "-----------------" << endl;
  }

  long int getApplicationID()
  {
    return applicationID;
  }

  void approveApplication(const long int appID)
  {
    
  }

  void rejectApplication()
  {
    applicationStatus = "REJECTED";
  }

  void saveToFile()
  {
    ofstream file("../data/applications.txt", ios::app);
    if (file.is_open())
    {
      file << applicationID << " " << applicantID << " " << applicationStatus << " " << propertyName << " " << propertyCost << " " << salary << " " << PAN << " " << Aadhaar << "\n";
    }
    else
    {
      cerr << "Unable to open file for writing" << endl;
    }
    file.close();
  }

  static vector<Application> getApplications ()
  {
    vector<Application> result;

    ifstream input("../data/applications.txt");
    if (input)
    {

      string line;
      while (getline(input, line))
      {

        istringstream iss(line);
        long int applicationID;
        long int applicantID;
        string applicationStatus;
        string propertyName;
        long int propertyCost;
        long int salary;
        string PAN;
        string Aadhaar;

        iss >> applicationID;
        iss >> applicantID;
        iss >> applicationStatus;
        iss >> propertyName;
        iss >> propertyCost;
        iss >> salary;
        iss >> PAN;
        iss >> Aadhaar;
        Application tempApp(applicationID, applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus);
        result.push_back(tempApp);
      }
    }
    return result;
  };

  static Application getApplication (const long int appID){
    long int applicationID;
    long int applicantID;
    string applicationStatus;
    string propertyName;
    long int propertyCost;
    long int salary;
    string PAN;
    string Aadhaar;
    ifstream input("../data/applications.txt");
    if(input){
      string line;
      while (getline(input, line)){
        istringstream iss(line);
        iss >> applicationID;
        if(applicationID==appID){
          cout << "Found matching application\n";
          iss >> applicantID;
          iss >> applicationStatus;
          iss >> propertyName;
          iss >> propertyCost;
          iss >> salary;
          iss >> PAN;
          iss >> Aadhaar;
          Application tempApp(applicationID, applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus);
          return tempApp;
        }
      }
    }
    throw exception(); 
  }

  static void deleteApplication (const long int appID){
    long int applicationID;
    ifstream input("../data/applications.txt");
    ofstream output("../data/tempApplications.txt");
    if(input){
      string line;
      while (getline(input, line)){
        istringstream iss(line);
        iss >> applicationID;
        if(applicationID==appID){
          cout << "Deleting matching application\n";
          continue;
        }
        if(output.is_open()){
          output << line << endl;
        } else {
          cerr << "Unable to open file for writing" << endl;
        }
      }
      input.close();
      output.close();
    } else {
      cerr << "Unable to open file for reading" << endl;
    }
    filesystem::remove("../data/applications.txt");
    filesystem::rename("../data/tempApplications.txt", "../data/applications.txt");
  }

};