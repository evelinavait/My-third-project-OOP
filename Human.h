#ifndef HUMAN_H
#define HUMAN_H

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

/// Bazinė (abstrakti) klasė, skirta bendrai aprašyti žmogų Human
/// 
/// Šioje klasėje negalima sukurti žmogaus tipo objektų, žmogaus kintamieji vardas (firstName) ir pavardė (lastName) yra apsaugoti
class Human
{
public:
    virtual ~Human() = 0; // make Human an abstract class by adding "= 0" to the declaration of the destructor

    /// Getter'is nustatantis žmogaus vardą
    /// @returns Grąžina žmogaus vardą
    inline std::string firstName() const { return firstName_; }    // getters, inline

    /// Getter'is nustatantis žmogaus pavardę
    /// @returns Grąžina žmogaus pavardę
    inline std::string lastName() const { return lastName_; }  // getters, inline

    /// Setter'is nustatantis žmogaus vardą
    /// @param v Kintamasis atitinka žmogaus vardą
    void setFirstName(string& v) { firstName_ = v; }

    /// Setter'is nustatantis žmogaus pavardę
    /// @param p Kintamasis atitinka žmogaus pavardę
    void setLastName(string& p) { lastName_ = p; }

protected:
    /// Apsaugotas vardo (firstName) kintamasis (string tipo) ir gaunamas tik naudojant išvestinę klasę, kuri paveldi
    string firstName_;

    /// Apsaugotas pavardės (lastName) kintamasis (string tipo) ir pasiekiamas tik klasei, kuri paveldi Human klasę
    string lastName_;
};

#endif // HUMAN_H
