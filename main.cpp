#include "include\Student.h"

string ToString(int value){
    stringstream ss;
    std::string s;
    ss << value;
    ss >> s;

    return s;
}

void CalculateTimeAndPrint(clock_t begin, clock_t end){
    double timer = double(end - begin) / CLOCKS_PER_SEC;
    cout << timer << endl;
}

bool SmartAndStupid(vector<Student> students)
{
    vector<Student> stupid;
    vector<Student> smart;

    clock_t begin = clock();
    sort(students.begin(), students.end());
    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
//    CalculateTimeAndPrint(begin, end);

    begin = clock();
    for(int i=0; i < students.size(); i++)
    {
        if(students[i].Final() < 5)
        {
            stupid.push_back(students[i]);
        }
        else
        {
            smart.push_back(students[i]);
        }
    }
    end = clock();

    cout << students.size() << " Irasu dalijimo i dvi grupes laikas (Vector): ";
    CalculateTimeAndPrint(begin, end);
}


vector<Student> ReadFromFile (string fileName){
    clock_t begin = clock();
    ifstream inFile;
    inFile.open(fileName.c_str());
    string line;
    vector<Student> myVec;//create a vector of Student objects
    if(inFile)
    {
        int k = 0;
        while(getline(inFile, line))
        {
            k++;
            if (k < 2)
                continue;

            Student s(line);

            myVec.push_back(s);
        }
    }
    else
    {
        cout << "Failas negali buti atidarytas" << endl;
    }


    clock_t end = clock();
    cout << endl << "Failo is " << myVec.size() << " irasu nuskaitymo laikas (Vector): ";
    CalculateTimeAndPrint(begin, end);
    return myVec;
}

void GetStudents(int cStudents){
    string fileNameToFunction = "files/" + ToString(cStudents) + "-studentai.txt";
    vector<Student> readFromFile = ReadFromFile(fileNameToFunction);
}

int main()
{
    GetStudents(1000);

    return 0;
}
