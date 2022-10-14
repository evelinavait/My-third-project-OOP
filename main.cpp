#include "my_lib.hpp"

struct student {
    string firstName;
    string lastName;
    vector<int> grade;
    int exam;
    float final;
    int median;
};

bool compareInterval(student i1, student i2)
{
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

void PrintStudents(vector<student> students, string fileName)
{
    fileName = "files/" + fileName + "-studentai.txt";
    ofstream MyFile;
    MyFile.open(fileName.c_str());
    //header
    //cout << setw(10) << left << "Vardas" << setw(10) << left << "Pavarde" << setw(19) << left << "Galutinis (Vid.) / " << setw(10) << left << "Galutinis (Med.)"<< endl;
    //cout << "-----------------------------------------------------" << endl;
    //MyFile << setw(10) << left << "Vardas" << setw(10) << left << "Pavarde" << setw(19) << left << "Galutinis (Vid.) / " << setw(10) << left << "Galutinis (Med.)"<< endl;
    //MyFile << "-----------------------------------------------------" << endl;
    for(int i=0; i < students.size(); i++)
    {
        //cout << setw(10) << left << students[i].firstName << setw(10) << left << students[i].lastName << setw(19) << left << students[i].final << setw(10) << left << students[i].median << endl;
        MyFile << setw(10) << left << students[i].firstName << setw(10) << left << students[i].lastName << setw(19) << left << students[i].final << setw(10) << left << students[i].median << endl;
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

student CreateStudent(int cGrades, int studentId) {
    stringstream ss;
    student newStudent;
    string id;
    ss << studentId;
    ss >> id;
    newStudent.firstName = "V" + id;
    newStudent.lastName = "P" + id;
    newStudent.exam = (rand() % 10) + 1;
    for(int i=0;i<cGrades;i++)
    {
        int g = (rand() % 10) + 1;
        newStudent.grade.push_back(g);
    }

    newStudent.final = Final(newStudent.exam, newStudent.grade);
    newStudent.median = Median(newStudent.grade);

    return newStudent;
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

    //begin = clock();
    //vector<students> readFromFile = ReadFromFile("1000-students");
    //end = clock();
    //cout << "Failo is " << students.size() << " irasu nuskaitymo laikas: \n";
    //CalculateTimeAndPrint(begin, end);

    SmartAndStupid(students);
    clock_t end = clock();

    cout << endl << students.size() << " Irasu testavimo laikas: ";
    CalculateTimeAndPrint(begin, end);

    cout << endl;

    return students;
}

int main()
{
    srand(time(0));

    GetStudents(1000);
    GetStudents(10000);
    GetStudents(100000);
    GetStudents(1000000);

    return 0;
}
