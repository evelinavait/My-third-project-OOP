#include "../calculations.h"
#include "Human.h"

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

class Student : public Human
{
    public:
        Student(){}; //global constructor
        Student(string line); //constructor
        Student(int id, int grades);
        ~Student();
        Student(const Student& other);
        Student& operator = (const Student& other);

        // getters, inline
        inline int HowManyGrade() const { return grade_.size(); }
        inline int GetGrade(int number) const { return grade_[number]; }
        float Final();

        // setters
        void setExam(int& e) { exam_ = e; }

    private:
        //string firstName_; //globalus kintamasis
        //string lastName_;
        vector<int> grade_;
        float exam_;
};

bool compareName(const Student& a, const Student& b);

bool compareFinal(const Student& a, const Student& b);

#endif // STUDENT_H
