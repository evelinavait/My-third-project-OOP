#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>

using std::vector;
using namespace std;

string ToString(int value);
float Final(int exam, vector<int> grade);
int Median(vector<int> arr);

#endif // CALCULATIONS_H_INCLUDED
