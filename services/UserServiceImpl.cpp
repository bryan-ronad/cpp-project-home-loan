#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"
#include "UserService.h"
#include "../repo/UserDAOImpl.h"

class UserServiceImpl : public UserService {
    private:
        UserDAOImpl userDaoObj;

    public:
        UserServiceImpl(UserDAOImpl userDaoObj){
            this->userDaoObj = userDaoObj;
        }

        User login(long int applicantID, string password)
        {
            long int _applicantID;
            string _password;
            string first_name;
            string last_name;
            long int salary;
            string PAN;
            string Aadhaar;
            bool is_admin;
            User temp_user;
            ifstream input("../db/users.data");
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
                            User temp_user(_applicantID, _password, first_name, last_name, salary, PAN, Aadhaar, is_admin);
                            cout << "Logged In Successfully \n";
                            return temp_user;
                        }
                        else
                        {
                            cout << "Wrong password" << endl;
                            return temp_user;
                        }
                    }
                }
            }
            return temp_user;
        }

        User logout()
        {
            User user;
            cout << "Logged Out \n";
            return user;
        }

        bool checkEligibility(Application application)
        {
            User applicant = userDaoObj.getUser(application.getApplicantID());
            /*
            Eligibility checking function 
            */
            
            return true;
        }
};