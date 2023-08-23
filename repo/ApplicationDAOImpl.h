#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <filesystem>
#include "ApplicationDAO.h"
#include "../models/Application.h"
using namespace std;

class ApplicationDAOImpl : public ApplicationDAO {
  public:
  Application createApplication(long int applicantID, string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, string applicationStatus = "PENDING"){
    Application tempApplication = Application(applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus);
    return tempApplication;
  }

  long int getApplicationID(Application application)
  {
    return application.getApplicationID();
  }

  void approveApplication(Application application)
  {
    application.setApplicationStatus("APPROVED"); 
  }

  void rejectApplication(Application application)
  {
    application.setApplicationStatus("REJECTED"); 
  }

  void saveToFile(Application application)
  {
    ofstream fout("../db/applications.data", ofstream::app);
    if (fout.is_open())
    {
      fout<<application;
    }
    else
    {
      cerr << "Unable to open file for writing" << endl;
    }
    fout.close();
  }

  static map<long int, Application> getApplications()
  {
    Application tempApp;
    map<long int, Application> tempMap;
    ifstream input("../db/applications.data");
    if(input){
      string line;
      while(getline(input, line)){
        istringstream iss(line);
        iss>>tempApp;
        tempMap.insert(make_pair(tempApp.getApplicationID(), tempApp));
      }
    }
    return tempMap;
  };

  static Application getApplication(const long int appID){
    map<long int, Application> applicationMap = ApplicationDAOImpl::getApplications();
    return applicationMap[appID];
  }

  void deleteApplication(Application application){
    map<long int, Application> applicationMap = ApplicationDAOImpl::getApplications();
    // Find key and delete in map
    map<long int, Application>::iterator iter = applicationMap.find(application.getApplicationID());
    if(iter==applicationMap.end()) throw exception();
    applicationMap.erase(iter);
    ofstream output("../db/tempApplications.data");
    if(output){
      for(iter=applicationMap.begin(); iter!=applicationMap.end(); iter++){
        output<<iter->second;
      }
    } else {
      cerr << "Unable to open file for writing" << endl;
    }
    output.close();
    filesystem::remove("../db/applications.data");
    filesystem::rename("../db/tempApplications.data", "../db/applications.data");
  }

  void updateApplicationStatus(Application application, string status){
    map<long int, Application> applicationMap = ApplicationDAOImpl::getApplications();
    Application tempApplication = applicationMap[application.getApplicationID()];
    if(status=="APPROVED"){
      tempApplication.setApplicationStatus("APPROVED");
    } else if (status=="REJECTED") {
      tempApplication.setApplicationStatus("REJECTED");
    }
    // Find key and update in map
    map<long int, Application>::iterator iter = applicationMap.find(application.getApplicationID());
    if(iter==applicationMap.end()) throw exception();
    iter->second = tempApplication;
    ofstream output("../db/tempApplications.data");
    if(output){
      for(iter=applicationMap.begin(); iter!=applicationMap.end(); iter++){
        output<<iter->second;
      }
    } else {
      cerr << "Unable to open file for writing" << endl;
    }
    output.close();
    filesystem::remove("../db/applications.data");
    filesystem::rename("../db/tempApplications.data", "../db/applications.data");
  }
};