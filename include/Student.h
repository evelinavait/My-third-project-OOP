#include "../calculations.h"

#ifndef STUDENT_H
#define STUDENT_H

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

class Student
{
    public:
        Student(string line); //constructor
        Student(int id, int grades);
        ~Student();
        Student(const Student& other);
        Student& operator = (const Student& other);

        // getters, inline
        inline std::string firstName() const { return firstName_; }
        inline std::string lastName() const { return lastName_; }
        inline int HowManyGrade() const { return grade_.size(); }
        inline int GetGrade(int number) const { return grade_[number]; }
        float Final();

        // setters
        void setFirstName(string& v) { firstName_ = v; }
        void setLastName(string& p) { lastName_ = p; }
        void setExam(int& e) { exam_ = e; }

    private:
        string firstName_; //global variable
        string lastName_;
        vector<int> grade_;
        float exam_;
};

bool compareName(const Student& a, const Student& b);

bool compareFinal(const Student& a, const Student& b);

#endif // STUDENT_H
