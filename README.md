# My-first-project-OOP
Project C++ Programming

# [v0.1 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v0.1)
Papildyta programa taip, kad ji veiktų ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Ši dalis realizuota rezultatus saugant į: [std::vector] tipo konteinerį.

# [v0.2 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v0.2)
main.cpp ir my_lib.hpp
`v0.1` versija naudojant tradicinį dinaminį C masyvą.

# [v0.2.1 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v0.2.1)

main2.cpp ir my_lib2.hpp
* `v0.2` versijoje yra sukuriamas ir užpildomas failas "kursiokai.txt". 
* Nuskaitomi duomenys iš failo ir išvedami rezultatai.
* Minimaliai panaudotas išimčių valdymas

# [v0.3 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v0.3)
* Sugeneruojami atsitiktiniai studentų sąrašų failai, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000 įrašų. Vardai ir Pavardės generuojami "šabloniniai", kaip pvz. `Vardas1 Pavarde1`, `Vardas2 Pavarde2` ir t.t.
* Studentai surūšiuojami didėjimo tvarka ir padalinami į dvi kategorijas:
  * Studentai, kurių galutinis balas < 5.0 - nelaimingi
  * Studentai, kurių galutinis balas >= 5.0 - protingi
* Surūšiuoti studentai išvedami į du naujus failus `-nelaimingi-studentai.txt` ir `-protingi-studentai.txt`. Failai pateikiami [files](https://github.com/evelinavait/My-first-project-OOP/tree/V0.3/files) aplankale.
* Atliekama programos veikimo greičio (spartos) analizė: t.y. išmatuojama programos sparta išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
    - [x] failų kūrimą;
    - [ ] duomenų nuskaitymą iš failų;
    - [x] rūšiavimą didėjimo tvarka, naudojant `sort` funkciją
    - [x] studentų dalijimą į dvi grupes/kategorijas;
    - [x] surūšiuotų studentų išvedimą į du naujus failus.

|Įrašai|Bendras įrašų testavimo laikas|Rūšiavimas didėjimo tvarka |Dalijimas į dvi grupes|Išvedimas į nelaimingi.txt |  Išvedimas į protingi.txt
|:---:|:---:|:---:|:---:|:---:|:---:
|1000 įrašų| 0.027|0.005|0 |0.002|0.004|
|10000 įrašų|0.173|0.062 |0.004|0.015|0.02|
|100000 įrašų|2.052|0.884 |0.056 |0.233|0.196|
|1000000 įrašų|22.406|10.739|0.614|1.417|2.605|

# v0.3.1 versija #
Patobulinta `v0.3` versijos realizacija
* Funkcijos, nauji duomenų tipai (struct’ūros) perkeliami į antraštinius (angl. **header (*.h)**) failus.
* Sugeneruojami atsitiktiniai studentų sąrašų failai, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000 įrašų, kurių (preliminari) struktūra atitinka failų `Studentai*.txt failas testavimui` struktūrą. Vardai ir Pavardės generuojami "šabloniniai", kaip pvz. `Vardas1 Pavarde1`, `Vardas2 Pavarde2` ir t.t.
```
Vardas      Pavarde     ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Pavardė1    8    9     10   6    10   9
Vardas2     Pavardė2    7    10    8    5    4    6
...
```
* Atliekama programos veikimo greičio (spartos) analizė: t.y. išmatuojama programos sparta išskiriant kiek laiko užtruko:
    - [x] duomenų nuskaitymą iš failų;
* Programa papildoma taip, kad ji veiktų, kai įrašų skaičius (n) yra nežinomas iš anksto, t.y. vartotojas įvedant į konsolę nusprendžia, kokį failą generuoti.
* Minimaliai panaudojamas išimčių valdymas (v0.2.1 versijoje buvo panaudota `readFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);`)
 ```c++
 try {
        cout << "Iveskite studentu kieki: ";
        cin >> c;
        GetStudents(c);
     } catch(const ios_base::failure& e) {
        cout << "Netinkamai ivestas studentu kiekis" << endl;
        cout << e.what() << endl;
}
```
# v0.4 versija
* Atliekamas **konteinerių testavimas**: išmatuojama patobulintos v0.3.1 realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
    * [std::vector](http://en.cppreference.com/w/cpp/container/vector)
    * [std::list](http://en.cppreference.com/w/cpp/container/list)

:heavy_exclamation_mark: matuojami šie programoje atliekami žingsniai:
    * duomenų nuskaitymas iš failų;
    * studentų rūšiavimas į dvi grupes/kategorijas;


Testavimas atliekamas su tais pačiais failais, sudarytais iš 1 000, 10 000, 100 000, 1 000 000 įrašų.




