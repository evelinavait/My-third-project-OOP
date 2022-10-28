# My-first-project-OOP #
Project C++ Programming

# v0.1 versija
Papildyta programa taip, kad ji veiktų ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Ši dalis realizuota rezultatus saugant į: [std::vector] tipo konteinerį.

# v0.2 versija
main.cpp ir my_lib.hpp
`v0.1` versija naudojant tradicinį dinaminį C masyvą.

# v0.2.1 versija

main2.cpp ir my_lib2.hpp
* `v0.2` versijoje yra sukuriamas ir užpildomas failas "kursiokai.txt". 
* Nuskaitomi duomenys iš failo ir išvedami rezultatai.
* Minimaliai panaudotas išimčių valdymas

# v0.3 versija #
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

![image](https://user-images.githubusercontent.com/72965991/198505710-49f994ae-f9a3-490a-8e56-bb956909c13b.png)


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
    - [x] duomenų nuskaitymas iš failų;
* Programa papildoma taip, kad ji veiktų, kai įrašų skaičius (n) yra nežinomas iš anksto, t. y. vartotojas įvedant į konsolę nusprendžia, kokį failą generuoti.
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
![1000](https://user-images.githubusercontent.com/72965991/198505285-532c0c77-7b4e-40d6-a6ae-e2dcad921821.png)
![10000](https://user-images.githubusercontent.com/72965991/198505302-b6be7151-c937-4c1b-b858-ff7b10c36a3c.png)
![100000](https://user-images.githubusercontent.com/72965991/198505415-0ba8136d-8aff-4dc3-850a-8218f158ab27.png)
![1000000](https://user-images.githubusercontent.com/72965991/198505439-cf7a7b0b-dc99-423d-90f1-f441353d54c0.png)

# v0.4 versija
* Atliekamas **konteinerių testavimas**: išmatuojama patobulintos v0.3.1 realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
    * [std::vector](http://en.cppreference.com/w/cpp/container/vector)
    * [std::list](http://en.cppreference.com/w/cpp/container/list)

:heavy_exclamation_mark:  Tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl `v0.4` versijoje matuojami šie programoje atliekami žingsniai:

* duomenų nuskaitymas iš failų;
* studentų rūšiavimas į dvi grupes/kategorijas;
    
Testavimas atliekamas su tais pačiais failais, sudarytais iš 1 000, 10 000, 100 000, 1 000 000 įrašų.

![v04_1000](https://user-images.githubusercontent.com/72965991/198581604-72588075-6dd8-4558-8203-e5212891c7f8.png)
![v04_10000](https://user-images.githubusercontent.com/72965991/198581810-02cf4b0f-bcc1-42b6-82df-c77f9bf4bef6.png)
![v04_100000](https://user-images.githubusercontent.com/72965991/198582187-753401a8-f541-43fe-b764-6a05ab3ead41.png)
![v04_1000000](https://user-images.githubusercontent.com/72965991/198583985-3f1a70d8-2480-4171-8e87-823c5563f558.png)
![CPU_1000000](https://user-images.githubusercontent.com/72965991/198590730-9ca5856c-0833-439e-b7a1-2bf903fae72d.png)
![CPU_1000000](https://user-images.githubusercontent.com/72965991/198592184-a0a12a6f-f7d2-4913-8bcd-54b29b7a3cce.png)

## Testų metu naudoto kompiuterio parametrai: ##

* Intel(R) Core(TM) i5-4200M CPU @ 2.50GHz 2.50 GHz
* 4GB RAM
* Windows 7 Ultimate; 64 bitų operacinė sistema
