#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <filesystem>
#include "User.h"
#include "UserService.h"
#include "HLApplication.h"
#include "UserDAOImpl.h"

class UserServiceImpl:public UserService  {
private:
    UserDAOImpl userDaoObj;


public:
    UserServiceImpl(UserDAOImpl _userDaoObj) {
        this->userDaoObj = _userDaoObj;
    }

    map<string, string> login(string applicantID, string password)
    {

        map<string, string> user_details;
        user_details["status_message"] = "";
        user_details["status_code"] = "500";
        string _applicantID;
        string _password;
        string first_name;
        string last_name;
        string salary;
        string PAN;
        string Aadhaar;
        string is_admin;
        User temp_user;




        ifstream input("users.txt");
        if (input)
        {
            string line;
            while (getline(input, line))
            {
                istringstream iss(line);
                iss >> _applicantID;
                iss >> _password;
                if (applicantID == _applicantID)
                {
                    if (password == _password)
                    {
                        iss >> first_name;
                        iss >> last_name;
                        iss >> salary;
                        iss >> PAN;
                        iss >> Aadhaar;
                        iss >> is_admin;
                        user_details["applicantID"] = _applicantID;
                        user_details["_password"] = _password;

                        user_details["first_name"] = first_name;

                        user_details["last_name"] = last_name;

                        user_details["salary"] = salary;
                        user_details["PAN"] = PAN;
                        user_details["Aadhaar"] = Aadhaar;

                        user_details["is_admin"] = is_admin;
                        cout << "----" << endl;
                        cout << is_admin << endl;
                        cout << "----" << endl;



                        user_details["status_message"] = "Logged In Successfully";
                        user_details["status_code"] = "200";
                        return user_details;
                    }
                    else
                    {
                        user_details["status_message"] = "Wrong Password, Please try again!";
                        return user_details;
                    }
                }
            }
        }


        user_details["status_message"] = "Invalid Credentials, Please try again!";

        return user_details;
    }

    map<string, string> signup(string password, string first_name, string last_name, long int salary, string PAN, string Aadhaar,bool is_admin ,string age, string job_type) {
        map<string, string> response;

        User user=userDaoObj.createUser(password, first_name, last_name, salary, PAN, Aadhaar, is_admin);
        userDaoObj.saveToFile(user);

        response["status_message"] = "Success";
        response["status_code"] = "200";
        return response;

        
        
    }
    bool logout()
    {
        cout << "Logged Out \n";

        return true;
    }
    bool checkEligibility(HLApplication application)
    {

        /*
        User applicant = userDaoObj.getUser(application.getApplicantID());
        Eligibility checking function
        */

        return true;
    }

};
