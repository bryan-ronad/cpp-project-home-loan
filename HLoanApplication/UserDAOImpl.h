#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <filesystem>
#include "UserDAO.h"
#include "User.h"
using namespace std;

class UserDAOImpl
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
        ifstream input("users.text");
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
        cout << "In save to file" << endl;
        ofstream fout("users.txt", ofstream::app);
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
        ofstream output("tempUsers.text");
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

        /*
        filesystem::remove("users.text");
        filesystem::rename("tempUsers.text", "users.text");
        */
    }
    bool isAdmin(User user)
    {
        return user.isAdmin();
    }
};