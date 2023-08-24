#pragma once
#include <bits/stdc++.h>
#include "UserDAO.h"
#include "../models/User.h"
using namespace std;

class UserDAOImpl : public UserDAO
{
public:
    User createUser(string password, string fname, string lname, long int salary, string PAN, string Aadhaar, bool is_admin)
    {
        User tempUser = User(password, fname, lname, salary, PAN, Aadhaar, is_admin);
        return tempUser;
    }

    long int getUserID(User user)
    {
        return user.getUserID();
    }

    static map<long int, User> getUsers()
    {
        User tempUser;
        map<long int, User> tempMap;
        ifstream input("../db/users.data");
        if (input)
        {
            string line;
            while (getline(input, line))
            {
                istringstream iss(line);
                iss >> tempUser;
                tempMap.insert(make_pair(tempUser.getUserID(), tempUser));
            }
        }
        return tempMap;
    };

    static User getUser(const long int userID)
    {
        map<long int, User> userMap = UserDAOImpl::getUsers();
        return userMap[userID];
    }

    void saveToFile(User user)
    {
        ofstream fout("../db/users.data", ofstream::app);
        if (fout.is_open())
        {
            fout << user;
        }
        else
        {
            cerr << "Unable to open file for writing" << endl;
        }
        fout.close();
    }

    void deleteUser(User user)
    {
        map<long int, User> userMap = UserDAOImpl::getUsers();
        // Find key and delete in map
        map<long int, User>::iterator iter = userMap.find(user.getUserID());
        if (iter == userMap.end())
            throw exception();
        userMap.erase(iter);
        ofstream output("../db/tempUsers.data");
        if (output)
        {
            for (iter = userMap.begin(); iter != userMap.end(); iter++)
            {
                output << iter->second;
            }
        }
        else
        {
            cerr << "Unable to open file for writing" << endl;
        }
        output.close();
        filesystem::remove("../db/users.data");
        filesystem::rename("../db/tempUsers.data", "../db/users.data");
    }

    bool isAdmin(User user)
    {
        return user.isAdmin();
    }
};