#include "student.h"

bool compareInterval(student i1, student i2){
    return (i1.final < i2.final);
}

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

void PrintStudents(vector<student> students, string fileName)
{
    fileName = "files/" + fileName + "-studentai.txt";
    ofstream MyFile;
    MyFile.open(fileName.c_str());
    //header

    MyFile << setw(10) << left << "Vardas" << setw(10) << left << "Pavarde";// << "Galutinis (Vid.) / " << setw(10) << left << "Galutinis (Med.)"<< endl;
    for(int i=0; i < students[0].grade.size(); i++)
        MyFile << setw(10) << left << "ND"+ToString(i+1); //<< left; //<< students[i].lastName << setw(19) << left; //<< students[i].final << setw(10) << left << students[i].median << endl;
    MyFile << setw(10) << left << "Egzaminas";
    MyFile << "-------------------------------------------------------------------------------" << endl;
    for(int i=0; i < students.size(); i++)
    {
        //cout << setw(10) << left << students[i].firstName << setw(10) << left << students[i].lastName << setw(19) << left << students[i].final << setw(10) << left << students[i].median << endl;
        MyFile << setw(10) << left << students[i].firstName << setw(10) << left << students[i].lastName << setw(19) << left; //<< students[i].final << setw(10) << left << students[i].median << endl;
        for(int j=0; j < students[i].grade.size(); j++)
            MyFile << setw(10) << left << students[i].grade[j] << setw(10); //<< left; //<< students[i].lastName << setw(19) << left; //<< students[i].final << setw(10) << left << students[i].median << endl;
        MyFile << setw(10) << left << students[i].final << endl;
    }
    MyFile.close();
}

bool SmartAndStupid(vector<student> students)
{
    vector<student> stupid;
    vector<student> smart;

    clock_t begin = clock();
    sort(students.begin(), students.end(), compareInterval);
    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
//    CalculateTimeAndPrint(begin, end);

    begin = clock();
    for(int i=0; i < students.size(); i++)
    {
        if(students[i].final < 5)
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

    begin = clock();
    PrintStudents(stupid, ToString(students.size()) + "nelaimingi");
    end = clock();
//    cout << students.size() << " Irasu nelaimingi irasymo i faila laikas (Vector): ";
//    CalculateTimeAndPrint(begin, end);

    begin = clock();
    PrintStudents(smart, ToString(students.size()) + "protingi");
    end = clock();
//    cout << students.size() << " Irasu protingi irasymo i faila laikas (Vector): ";
//    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupid2NotOptim(vector<student> students){
    int vectorSize = students.size();

    clock_t begin = clock();
//    clock_t begin = clock();
    sort(students.begin(), students.end(), compareInterval);
//    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
//    CalculateTimeAndPrint(begin, end);
    vector<student> stupid;
    vector<student>::iterator it = students.begin();
    while (it != students.end()) {
    if ((*it).final < 5) {
    stupid.push_back(*it);
    it = students.erase(it);
    } else
    ++it;
    }
    clock_t end = clock();
    cout << vectorSize << " Irasu dalijimo i dvi grupes laikas (Vector), neoptimizuotas: ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupid2(vector<student> students)
{
    int vectorSize = students.size();
    clock_t begin = clock();
//    clock_t begin = clock();
    sort(students.begin(), students.end(), compareInterval);
//    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (Vector): ";
//    CalculateTimeAndPrint(begin, end);

    vector<student>::iterator it;
    it = stable_partition(students.begin(), students.end(), [](student S) {return S.final > 5;});
    vector<student> stupid(it, students.end());
    students.erase(it, students.end());

    clock_t end = clock();
    cout << vectorSize << " Irasu dalijimo i dvi grupes laikas (Vector), optimizuotas: ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupidl(list<student> students){
    list<student> stupid;
    list<student> smart;
    int listSize = students.size();

    clock_t begin = clock();
//    clock_t begin = clock();
    students.sort(compareInterval);
//    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (List): ";
//    CalculateTimeAndPrint(begin, end);

    list<student>::iterator it = students.begin();
    while(it != students.end()){
            //cout << (*it).final << endl;
        if ((*it).final < 5) {
            stupid.push_back(*it); // dereference *it kad gauti elementą
        } else {
            smart.push_back(*it);
        }
            //it = students.erase(it);
            ++it;
    }
    clock_t end = clock();
    cout << listSize << " Irasu dalijimo i dvi grupes laikas (List): ";
    CalculateTimeAndPrint(begin, end);
}

void SmartAndStupidl2(list<student> students){
    int listSize = students.size();

    clock_t begin = clock();
//    clock_t begin = clock();
    students.sort(compareInterval);
//    clock_t end = clock();
//    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija (List): ";
//    CalculateTimeAndPrint(begin, end);
    list<student> stupid;
    list<student>::iterator it = students.begin();
    while (it != students.end()) {
    if ((*it).final < 5) {
    stupid.push_back(*it); // dereference *it kad gauti elementą
    it = students.erase(it); // perduodame it, gauname it
    } else
    ++it; // pereiti prie kito studento
    }
    clock_t end = clock();
    cout << listSize << " Irasu dalijimo i dvi grupes laikas (List): ";
    CalculateTimeAndPrint(begin, end);
}

student CreateStudent(int cGrades, int studentId){
    stringstream ss;
    student newStudent;
    string id;
    ss << studentId;
    ss >> id;
    newStudent.firstName = "V" + id;
    newStudent.lastName = "P" + id;
    newStudent.exam = (rand() % 10) + 1;
    for(int i=0; i<cGrades; i++)
    {
        int g = (rand() % 10) + 1;
        newStudent.grade.push_back(g);
    }

    newStudent.final = Final(newStudent.exam, newStudent.grade);
    newStudent.median = Median(newStudent.grade);

    return newStudent;
}

vector<student> ReadFromFile (string fileName){
    clock_t begin = clock();
    ifstream inputFile(fileName);
    string line;
    vector<student> myVec;//create a vector of Student objects
    if(inputFile)
    {
        int k;
        k = 0;
        while(getline(inputFile, line))
        {
            k++;
            if (k < 2)
            continue;
            student studentObject;
            istringstream st(line);
            st >> studentObject.firstName; //read the firstName
            st >> studentObject.lastName; //read the lastName
            for (int i = 0; i< 5; i++){
                string nd;
                st >> nd;
                //cout << nd << endl;
                studentObject.grade.push_back(stoi(nd));
            }
            st >> studentObject.final;

            if(st)//check if input succeded
            {
                myVec.push_back(studentObject);//add the studentObject into the vector
            }
        }
    }
    else
    {
        cout << "Failas negali buti atidarytas" << endl;
    }

//    for(const student &elem: myVec)
//    {
//        std::cout <<elem.firstName<<" "<<elem.lastName<<" "<<elem.final<<" "<<std::endl;
//    }
    clock_t end = clock();
    cout << endl << "Failo is " << myVec.size() << " irasu nuskaitymo laikas (Vector): ";
    CalculateTimeAndPrint(begin, end);

    return myVec;
}

list<student> ReadFromFileList (string fileName){
    clock_t begin = clock();
    ifstream inputFile(fileName);
    string line;
    list<student> myList;//create a list of Student objects
    if(inputFile)
    {
        int k;
        k = 0;
        while(getline(inputFile, line))
        {
            k++;
            if (k < 2)
            continue;
            student studentObject;
            istringstream st(line);
            st >> studentObject.firstName; //read the firstname
            st >> studentObject.lastName; //read the lastname
            for (int i = 0; i< 5; i++){
                string nd;
                st >> nd;
                //cout << nd << endl;
                studentObject.grade.push_back(stoi(nd));
            }
            st >> studentObject.final;

            if(st)//check if input succeded
            {
                myList.push_back(studentObject);//add the studentObject into the list
            }
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

void GetStudents(int cStudents){
    int cGrades = 5;

    string fileNameToFunction = "files/" + ToString(cStudents) + "-studentai.txt";
    ifstream ifile;
    ifile.open(fileNameToFunction);
    if(!ifile) {
        cout << "Failas generuojamas" << endl;
        vector<student> students;
        for(int i=0; i < cStudents; i++)
        {
            student singleStudent = CreateStudent(cGrades, i+1);
            students.push_back(singleStudent);
        }

        stringstream ss;
        std::string stringStudents;
        ss << cStudents;
        ss >> stringStudents;

        PrintStudents(students, stringStudents);
}
        else {
        cout << "Failas jau egzistuoja" << endl;
        ifile.close();
        }
    vector<student> readFromFile = ReadFromFile(fileNameToFunction);
    list<student> readFromFileList = ReadFromFileList(fileNameToFunction);

    cout << endl << "Strategija 1" << endl;
//    clock_t begin = clock();
    SmartAndStupid(readFromFile);
    SmartAndStupidl(readFromFileList);
//    clock_t end = clock();

    cout << endl << "Strategija 2" << endl;
//    clock_t begin = clock();
//    SmartAndStupid2NotOptim(readFromFile);
    SmartAndStupid2(readFromFile);
    SmartAndStupidl2(readFromFileList);
//    clock_t end = clock();
//
//    cout << endl << students.size() << " Irasu testavimo laikas (Vector): ";
//    CalculateTimeAndPrint(begin, end);
}
