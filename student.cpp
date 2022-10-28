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
    cout << students.size() << " Irasu rusiavimo didejimo tvarka laikas, su sort funkcija: ";
    CalculateTimeAndPrint(begin, end);

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

    cout << students.size() << " Irasu dalijimo i dvi grupes laikas: ";
    CalculateTimeAndPrint(begin, end);

    begin = clock();
    PrintStudents(stupid, ToString(students.size()) + "nelaimingi");
    end = clock();
    cout << students.size() << " Irasu nelaimingi irasymo i faila laikas: ";
    CalculateTimeAndPrint(begin, end);

    begin = clock();
    PrintStudents(smart, ToString(students.size()) + "protingi");
    end = clock();
    cout << students.size() << " Irasu protingi irasymo i faila laikas: ";
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
        cout<<"Failas negali buti atidarytas"<<endl;
    }

//    for(const student &elem: myVec)
//    {
//        std::cout <<elem.firstName<<" "<<elem.lastName<<" "<<elem.final<<" "<<std::endl;
//    }
    clock_t end = clock();
    cout << "Failo is " << myVec.size() << " irasu nuskaitymo laikas: ";
    CalculateTimeAndPrint(begin, end);

    return myVec;
}

vector<student> GetStudents(int cStudents){
    clock_t begin = clock();
    int cGrades = 5;

    string check;
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

    string fileNameToFunction = "files/" + ToString(cStudents) + "-studentai.txt";
    vector<student> readFromFile = ReadFromFile(fileNameToFunction);

    SmartAndStupid(students);
    clock_t end = clock();
    cout << endl << students.size() << " Irasu testavimo laikas: ";
    CalculateTimeAndPrint(begin, end);

    cout << endl;

    return students;
}
