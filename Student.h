#include "calculations.h"
#include "Human.h"

#ifndef STUDENT_H
#define STUDENT_H

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

/// Išvestinė (angl. derived) klasė - Student
///
///
class Student : public Human
{
public:
    /// Numatytasis (angl. default) konstruktorius
    /// 
    /// Sukonstruoja Student tuščią objektą.
    Student() {}; // default constructor

    /// Konstruktorius, kuris apima vieną simbolių eilučių tipo parametrą - line. 
    /// 
    /// Skirtas sukurti Student klasės objektą pagal duotą parametrą line
    /// @param line Simbolių eilučių tipo kintamasis
    Student(string line); // constructor

    /// Konstruktorius, skirtas sukurti objektą pateiktiems duomenims
    /// 
    /// Šis konstruktorius sukuria Student klasės kintamąjį, nurodant ID ir pažymių įverčius
    /// @param id Studento identifikacinis numeris
    /// @param grades Namų darbų pažymiai
    Student(int id, int grades); // global constructor

    /// Destruktorius
    ///
    /// 
    ~Student(); // I. destructor

    /// Kopijavimo konstruktorius
    /// 
    /// Skirtas nukopijuoti studento informaciją iš vieno į kitą
    /// @param other Informacija studento, kurio duomenis kopijuojame
    Student(const Student& other); // II. copy constructor

    /// Kopijavimo priskirties operatorius
    /// 
    /// Lygybės operatoriaus perdengimas
    /// @param other Informacija studento, kurį norime nukopijuoti
    /// @returns Nukopijuoja Student klasės kintamąjį ir jį priskiria kitam (juos sulygina)
    Student& operator = (const Student& other); // III. copy assignment

    /// Getter'is atiduodantis namų darbų pažymių skaičių
    /// 
    /// @returns Grąžina sveikąjį skaičių, nurodantį elementų skaičių vektoriuje grade_.
    inline int HowManyGrade() const { return grade_.size(); }

    /// Getter'is atiduodantis studento pažymį, indeksuotą konteineryje
    /// 
    /// @param [number] Studento pažymys, pažymėtas indeksu
    /// @return Grąžina studento pažymį
    inline int GetGrade(int number) const { return grade_[number]; }

    /// Getter'is atiduodantis studento galutinį įvertinimą
    /// 
    /// @returns Grąžina studento galutinį įvertinimą
    float Final() const;

    /// Setter'is
    /// 
    /// void negrąžina jokios reikšmės
    /// @param e Naudojamas egzamino reikšmei nustatyti
    void setExam(int& e) { exam_ = e; }

    /// Įvedimo operacijos funkcijos perdengimas
    /// 
    /// 
    /// @param istream& in Nuoroda į įvesties srauto objektą
    /// @param Student& s Nuoroda į Student objektą
    /// @returns Funkcija grąžina nuorodą į įvesties srauto objektą
    friend istream& operator>>(istream& in, Student& s);

    /// Išvedimo operacijos funkcijos perdengimas
    /// 
    /// @param ostream& out Nuoroda į išvesties srauto objektą
    /// @param Student& s Nuoroda į Student objektą
    /// @returns Funkcija grąžina nuorodą į išvesties srauto objektą (ostream nuorodą).
    friend ostream& operator<<(ostream& out, const Student& s);

private:
    vector<int> grade_;
    float exam_;
};

bool compareName(const Student& a, const Student& b);

bool compareFinal(const Student& a, const Student& b);

#endif // STUDENT_H

