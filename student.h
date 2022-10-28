#include "calculations.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
using std::vector;
using namespace std;

struct student {
    string firstName;
    string lastName;
    vector<int> grade;
    int exam;
    float final;
    int median;
};

bool compareInterval(student i1, student i2);
string ToString(int value);
void CalculateTimeAndPrint(clock_t begin, clock_t end);
void PrintStudents(vector<student> students, string fileName);
bool SmartAndStupid(vector<student> students);
student CreateStudent(int cGrades, int studentId);
vector<student> ReadFromFile (string fileName);
vector<student> GetStudents(int cStudents);

#endif // STUDENT_H_INCLUDED
