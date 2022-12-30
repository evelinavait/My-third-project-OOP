#include "Student.h"

Student::Student(int id, int grades)
{
    firstName_ = "V" + ToString(id);
    lastName_ = "P" + ToString(id);
    exam_ = (rand() % 10) + 1;
    for (int i = 0; i < grades; i++)
    {
        int g = (rand() % 10) + 1;
        grade_.push_back(g);
    }
}

Student::~Student() // I. destructor
{
    grade_.clear(); // deallocate
}

Student::Student(const Student& other) // II. copy constructor
{
    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
    grade_ = other.grade_;
    exam_ = other.exam_;
}

Student& Student:: operator = (const Student& other) // III. copy assignment
{
    if (this == &other)
        return *this;

    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
    grade_ = other.grade_;
    exam_ = other.exam_;
    return *this;
}

Student::Student(string line)
{
    istringstream st(line);
    st >> firstName_; //read the firstName
    st >> lastName_; //read the lastName
    for (int i = 0; i < 5; i++) {
        string nd;
        st >> nd;
        grade_.push_back(atoi(nd.c_str()));
    }

    st >> exam_;
}

float Student::Final() const
{
    int sum = 0;
    int cGrades = grade_.size();
    for (int i = 0; i < cGrades; i++)
    {
        sum = sum + grade_[i];
    }

    float vid = sum / (float)cGrades;

    return (0.6 * exam_) + (vid * 0.4);
}

istream& operator>>(istream& in, Student& s)
{
    cout << "Iveskite studento varda: ";
    in >> s.firstName_;
    cout << "Iveskite studento pavarde: ";
    in >> s.lastName_;
    cout << "Iveskite ND pazymius (5 pazymiai): ";
    for (int i = 0; i < 5; i++)
    {
        int grade;
        in >> grade;
        s.grade_.push_back(grade);
    }
    cout << "Iveskite studento egzamino pazymi: ";
    in >> s.exam_;
    return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
    out << endl << "Vardas: " << s.firstName_ << endl;
    out << "Pavarde: " << s.lastName_ << endl;
    out << "ND pazymiai: ";
    for (int i = 0; i < s.grade_.size(); i++)
    {
        out << s.grade_[i] << " ";
    }
    out << endl << "Studento egzamino pazymys: " << s.exam_ << endl;
    out << "Studento galutinis ivertinimas: " << s.Final() << endl;
    return out;
}

bool compareName(const Student& a, const Student& b)
{
    if (a.firstName() == b.firstName()) return a.lastName() < b.lastName();
    return a.firstName() < b.firstName();
}
