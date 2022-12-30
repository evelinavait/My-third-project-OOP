#include "calculations.h"
#include "Student.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
//#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
using std::vector;
using namespace std;

bool compareInterval(Student i1, Student i2);
string ToString(int value);
void CalculateTimeAndPrint(clock_t begin, clock_t end);
void PrintStudents(vector<Student> students, string fileName);
void SmartAndStupid(vector<Student> students);
void SmartAndStupid2NotOptim(vector<Student> students);
void SmartAndStupid2(vector<Student> students);
void SmartAndStupidl(list<Student> students);
void SmartAndStupidl2(list<Student> students);
Student CreateStudent(int cGrades, int studentId);
vector<Student> ReadFromFile(string fileName);
list<Student> ReadFromFileList(string fileName);
void GetStudents(int cStudents);

#endif // STUDENT_H_INCLUDED
#pragma once
#pragma once
