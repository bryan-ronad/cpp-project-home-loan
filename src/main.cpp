#include <bits/stdc++.h>
#include "../repo/ApplicationDAOImpl.h"
#include "../models/Application.h"
using namespace std;

int main()
{
  srand((unsigned)time(NULL));
  /*
  Clears the file for development purpose
  */
  // ofstream ofs;
  // ofs.open("../db/applications.data", ofstream::out | ofstream::trunc);
  // ofs.close();

  // Create ApplicationDAOImpl object
  ApplicationDAOImpl applicationDaoObj;
  Application application = applicationDaoObj.createApplication(
      4,
      "A_big_house",
      8000000,
      100000,
      "PANXXXX",
      "AAXXXX");
  Application application2 = applicationDaoObj.createApplication(
      5,
      "A_smaller_house",
      5000000,
      100000,
      "PANX",
      "AAX");

  // // Saving application object to file
  // applicationDaoObj.saveToFile(application);
  // applicationDaoObj.saveToFile(application2);

  // // Reading application vector from file
  // map<long int, Application> applicationMap = applicationDaoObj.getApplications();

  // // Looping over map and printing details of applications
  // map<long int, Application>::iterator it;
  // for (it = applicationMap.begin(); it != applicationMap.end(); it++)
  // {
  //   cout<<it->first<<" : "<<it->second;
  // }

  // // Testing the getApplicationByID method
  // Application application3 = applicationDaoObj.getApplication(3314);

  // // Testing the deleteApplication() function
  // applicationDaoObj.deleteApplication(application3);

  // // Testing the updateApplicationStatus() method
  // applicationDaoObj.updateApplicationStatus(application3, "APPROVED");
  
  return 0;
}