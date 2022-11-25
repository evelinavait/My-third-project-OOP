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
        Student(string line);

        //Student() : exam_(0) { }  // default konstruktorius
        //Student(std::istream& is);
        inline std::string firstName() const { return firstName_; }    // get'eriai, inline
        inline std::string lastName() const { return lastName_; }  // get'eriai, inline
        float Final();  // get'eriai //i fcija paduodam grades -> iskvieciam final
        //std::istream& readStudent(std::istream&);  // set'eria

    private:
        string firstName_; //globalus kintamasis
        string lastName_;
        vector<int> grade_;
        float exam_;
        //float final_;
        int median_;
};

// 1. copy constructor
//Student(const Student& that) : firstName(that.firstName), lastName(that.lastName)
//{
//}

// 2. copy assignment operator
//Student& operator=(const Student& that)
//{
//    firstName = that.firstName;
//    lastName = that.lastName;
//    return *this;
//}

// 3. destructor
//~Student()
//{
//}

//bool compare(const Student&, const Student&);

#endif // STUDENT_H
