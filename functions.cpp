#include "functions.h"
#include "Student.h"

bool compareInterval(Student i1, Student i2) {
    return (i1.Final() < i2.Final());
}

void CalculateTimeAndPrint(clock_t begin, clock_t end) {
    double timer = double(end - begin) / CLOCKS_PER_SEC;
    cout << timer << endl;
}

void PrintStudents(vector<Student> Students, string fileName)
{
    fileName = "files/" + fileName + "-Studentai.txt";
    ofstream MyFile;
    MyFile.open(fileName.c_str());
    //header

    MyFile << setw(10) << left << "Vardas" << setw(10) << left << "Pavarde";
    for (int i = 0; i < Students[0].HowManyGrade(); i++)
        MyFile << setw(10) << left << "ND" + ToString(i + 1);
    MyFile << setw(10) << left << "Egzaminas";
    MyFile << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < Students.size(); i++)
    {
        MyFile << setw(10) << left << Students[i].firstName() << setw(10) << left << Students[i].lastName() << setw(19) << left;
        for (int j = 0; j < Students[i].HowManyGrade(); j++)
            MyFile << setw(10) << left << Students[i].GetGrade(j) << setw(10);
        MyFile << setw(10) << left << Students[i].Final() << endl;
    }
    MyFile.close();
}
void SmartAndStupid(vector<Student> Students)
{
    vector<Student> stupid;
    vector<Student> smart;

    clock_t begin = clock();
    //sort(Students.begin(), Students.end(), compareInterval);
    clock_t end = clock();
    //    cout << Students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
    //    CalculateTimeAndPrint(begin, end);

    begin = clock();
    for (int i = 0; i < Students.size(); i++)
    {
        if (Students[i].Final() < 5)
        {
            stupid.push_back(Students[i]);
        }
        else
        {
            smart.push_back(Students[i]);
        }
    }
    end = clock();

    cout << Students.size() << " Irasu dalijimo i dvi grupes laikas (Vector): ";
    CalculateTimeAndPrint(begin, end);

    begin = clock();
    PrintStudents(stupid, ToString(Students.size()) + "nelaimingi");
    end = clock();
    //    cout << Students.size() << " Irasu nelaimingi irasymo i faila laikas (Vector): ";
    //    CalculateTimeAndPrint(begin, end);

    begin = clock();
    PrintStudents(smart, ToString(Students.size()) + "protingi");
    end = clock();
    //    cout << Students.size() << " Irasu protingi irasymo i faila laikas (Vector): ";
    //    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupid2NotOptim(vector<Student> Students) {
    int vectorSize = Students.size();
    clock_t begin = clock();
    //    clock_t begin = clock();
        //sort(Students.begin(), Students.end(), compareInterval);
    //    clock_t end = clock();
        //cout << Students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
    //    CalculateTimeAndPrint(begin, end);
    vector<Student> stupid;
    vector<Student>::iterator it = Students.begin();
    while (it != Students.end()) {
        if ((*it).Final() < 5) {
            stupid.push_back(*it);
            it = Students.erase(it);
        }
        else
            ++it;
    }

    clock_t end = clock();
    cout << vectorSize << " Irasu dalijimo i dvi grupes laikas (Vector), neoptimizuotas: ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupid2(vector<Student> Students)
{
    int vectorSize = Students.size();
    clock_t begin = clock();
    //    clock_t begin = clock();
        //sort(Students.begin(), Students.end(), compareInterval);
    //    clock_t end = clock();
    //    cout << Students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
    //    CalculateTimeAndPrint(begin, end);

    vector<Student>::iterator it;
    it = std::stable_partition(Students.begin(), Students.end(), [](Student S) {return S.Final() > 5;});
    vector<Student> stupid(it, Students.end());
    Students.erase(it, Students.end());

    clock_t end = clock();
    cout << vectorSize << " Irasu dalijimo i dvi grupes laikas (Vector), optimizuotas: ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupidl(list<Student> Students) {
    list<Student> stupid;
    list<Student> smart;
    int listSize = Students.size();

    clock_t begin = clock();
    //    clock_t begin = clock();
        //Students.sort(compareInterval);
    //    clock_t end = clock();
    //    cout << Students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (List): ";
    //    CalculateTimeAndPrint(begin, end);

    list<Student>::iterator it = Students.begin();
    while (it != Students.end()) {
        //cout << (*it).final << endl;
        if ((*it).Final() < 5) {
            stupid.push_back(*it); // dereference *it kad gauti elementą
        }
        else {
            smart.push_back(*it);
        }
        ++it;
    }
    clock_t end = clock();
    cout << listSize << " Irasu dalijimo i dvi grupes laikas (List): ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupidl2(list<Student> Students) {
    int listSize = Students.size();

    clock_t begin = clock();
    //    clock_t begin = clock();
        //Students.sort(compareInterval);
    //    clock_t end = clock();
    //    cout << Students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (List): ";
    //    CalculateTimeAndPrint(begin, end);
    list<Student> stupid;
    list<Student>::iterator it = Students.begin();
    while (it != Students.end()) {
        if ((*it).Final() < 5) {
            stupid.push_back(*it); // dereference *it kad gauti elementą
            it = Students.erase(it); // perduodame it, gauname it
        }
        else
            ++it; // pereiti prie kito Studento
    }
    clock_t end = clock();
    cout << listSize << " Irasu dalijimo i dvi grupes laikas (List): ";
    CalculateTimeAndPrint(begin, end);
}

vector<Student> ReadFromFile(string fileName) {
    clock_t begin = clock();
    ifstream inputFile(fileName.c_str());
    string line;
    vector<Student> myVec;//create a vector of Student objects
    if (inputFile)
    {
        int k;
        k = 0;
        while (getline(inputFile, line))
        {
            k++;
            if (k < 2)
                continue;

            Student s(line);

            myVec.push_back(s);//add the StudentObject into the vector
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

list<Student> ReadFromFileList(string fileName) {
    clock_t begin = clock();
    ifstream inputFile(fileName.c_str());
    string line;
    list<Student> myList;//create a list of Student objects
    if (inputFile)
    {
        int k;
        k = 0;
        while (getline(inputFile, line))
        {
            k++;
            if (k < 2)
                continue;
            Student s(line);

            myList.push_back(s);//add the StudentObject into the list
        }
    }
    else
    {
        cout << "Failas negali buti atidarytas" << endl;
    }

    clock_t end = clock();
    cout << "Failo is " << myList.size() << " irasu nuskaitymo laikas (List): ";
    CalculateTimeAndPrint(begin, end);

    return myList;
}

void GetStudents(int cStudents) {
    int cGrades = 5;

    string fileNameToFunction = "files/" + ToString(cStudents) + "-Studentai.txt";
    ifstream ifile;
    ifile.open(fileNameToFunction.c_str());
    if (!ifile) {
        cout << "Failas generuojamas" << endl;
        vector<Student> Students;
        for (int i = 0; i < cStudents; i++)
        {
            Student singleStudent(i + 1, cGrades);
            Students.push_back(singleStudent);
        }

        stringstream ss;
        std::string stringStudents;
        ss << cStudents;
        ss >> stringStudents;

        PrintStudents(Students, stringStudents);
    }
    else {
        cout << "Failas jau egzistuoja" << endl;
        ifile.close();
    }
    vector<Student> readFromFile = ReadFromFile(fileNameToFunction);
    list<Student> readFromFileList = ReadFromFileList(fileNameToFunction);

    cout << endl << "Strategija 1" << endl;
    //    clock_t begin = clock();
    SmartAndStupid(readFromFile);
    SmartAndStupidl(readFromFileList);
    //    clock_t end = clock();

    cout << endl << "Strategija 2" << endl;
    clock_t begin = clock();
    //SmartAndStupid2NotOptim(readFromFile);
    SmartAndStupid2(readFromFile); //1 list: readfromfile -> stupid trinam ir perkeliam i nauja list
    SmartAndStupidl2(readFromFileList);
    clock_t end = clock();

    cout << endl << readFromFile.size() << " Irasu testavimo laikas (Vector): ";
    CalculateTimeAndPrint(begin, end);
}
