#include <bits/stdc++.h>
#include "../models/User.h"

class UserService {
  public:
    virtual User login(long int applicantID, string password) = 0;
    virtual User logout() = 0;
    virtual bool checkEligibility(Application) = 0;
};