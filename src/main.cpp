#include <bits/stdc++.h>
#include "../models/Application.h"
#include "../models/User.h"
#include "../repo/ApplicationDAOImpl.h"
#include "../repo/UserDAOImpl.h"
#include "../services/ApplicationServiceImpl.cpp"
#include "../services/UserServiceImpl.cpp"
#include "../UI/Menu.cpp"
#include "../UI/List.cpp"
#include "../UI/Form.cpp"
using namespace std;

int main()
{
  /*
  SETUP/INITIALIZATIONS
  */
  ApplicationDAOImpl applicationDaoObj;
  UserDAOImpl userDaoObj;
  ApplicationServiceImpl applicationServiceObj(applicationDaoObj);
  UserServiceImpl userServiceObj(userDaoObj);
  srand((unsigned)time(NULL));

  /*
  Clears the file for development purpose
  */
  // ofstream ofs;
  // ofs.open("../db/applications.data", ofstream::out | ofstream::trunc);
  // ofs.close();

  // Application application = applicationServiceObj.createApplication(
  //     4,
  //     "A_big_house",
  //     8000000,
  //     100000,
  //     "PANXXXX",
  //     "AAXXXX");

  // Application application2 = applicationServiceObj.createApplication(
  //     5,
  //     "A_smaller_house",
  //     5000000,
  //     100000,
  //     "PANX",
  //     "AAX");

  /*
  1. LOGIN
  */
  // Taking username and password
  long int username;
  string password;
  cout<<"Enter your username: ";
  cin>>username;
  cout<<"Enter your password: ";
  cin>>password;
  // Calling service login function 
  User loggedInUser = userServiceObj.login(username, password);

  /*
  2. Admin menu
  */
  int mainMenuChoice;
  if (userDaoObj.isAdmin(loggedInUser)){
    Menu::adminMainMenu();   
    cin>>mainMenuChoice;
    /*
    3. Application Form
    */
    if(mainMenuChoice==1)
    {
      int adminChoice;
      Menu::adminFunctionalityMenu();
      cin>>adminChoice;
      if(adminChoice==1)
      {
        map<long int, Application> applicationMap = applicationServiceObj.getApplications();
        List::listApplications(applicationMap);
      } else if(adminChoice==2) {
        map<long int, Application> applicationMap = applicationServiceObj.getFilteredApplications("PENDING");
        List::listApplications(applicationMap);
      }
      int adminAppChoice;
      Menu::adminApplicationMenu();
      cin>>adminAppChoice;
      long int applicationID;
      cout<<"Enter application ID to perform action on: ";
      cin>>applicationID;
      if(adminAppChoice==1)
      {
        applicationServiceObj.updateApplicationStatus(applicationID, "APPROVED");
        map<long int, Application> applicationMap = applicationServiceObj.getApplications();
        List::listApplications(applicationMap);
      } else if (adminAppChoice==2) {
        applicationServiceObj.updateApplicationStatus(applicationID, "REJECTED");
        map<long int, Application> applicationMap = applicationServiceObj.getApplications();
        List::listApplications(applicationMap);
      } else if (adminAppChoice==3) {
        cout<<userServiceObj.checkEligibility(applicationDaoObj.getApplication(applicationID));
      }
    }
  } else {
    int nonAdminChoice;
    Menu::mainMenu();
    cin>>nonAdminChoice;
    if(nonAdminChoice==1){
      appFormStruct appFormInput = Form::applicationForm();
      Application createdApplication = applicationServiceObj.createApplication(
        loggedInUser.getUserID(), 
        appFormInput.propertyName, 
        appFormInput.propertyCost,
        appFormInput.salary,
        appFormInput.PAN,
        appFormInput.Aadhaar
        );
    }
  }
  return 0;
}