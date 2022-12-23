#ifndef HUMAN_H
#define HUMAN_H

#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
using std::vector;
using namespace std;


class Human
{
    public:
        inline std::string firstName() const { return firstName_; }    // get'eriai, inline
        inline std::string lastName() const { return lastName_; }  // get'eriai, inline

        virtual void setFirstName(string& v) { firstName_ = v; }
        virtual void setLastName(string& p) { lastName_ = p; }

    protected:
        string firstName_;
        string lastName_;
};

#endif // HUMAN_H
