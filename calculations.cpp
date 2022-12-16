#include "calculations.h"

float Final(int exam, vector<int> grade)
{
    int sum = 0;
    int cGrades = grade.size();
    for(int i=0; i < cGrades; i++)
    {
        sum = sum + grade[i];
    }

    float vid = sum/(float)cGrades;

    return (0.6 * exam) + (vid * 0.4);
}

int Median(vector<int> arr){
    int size = arr.size();
    sort(arr.begin(), arr.end());
    if (size % 2 != 0)
        return arr[size/2];
    return (arr[(size-1)/2] + arr[size/2])/2.0;
}

string ToString(int value){
    stringstream ss;
    std::string s;
    ss << value;
    ss >> s;

    return s;
}
