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

# [v0.3.1 versija](https://github.com/evelinavait/My-first-project-OOP/releases/tag/v0.3.1)
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
# [v0.4 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v0.4)
* Atliekamas **konteinerių testavimas**: išmatuojama patobulintos `v0.3.1` realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
    * [std::vector](http://en.cppreference.com/w/cpp/container/vector)
    * [std::list](http://en.cppreference.com/w/cpp/container/list)

:heavy_exclamation_mark:  Tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl `v0.4` versijoje matuojami šie programoje atliekami žingsniai:

* duomenų nuskaitymas iš failų;
* studentų rūšiavimas į dvi grupes/kategorijas;
    
Testavimas atliekamas su tais pačiais failais, sudarytais iš 1 000, 10 000, 100 000, 1 000 000 įrašų.

# [v0.4.1 versija](https://github.com/evelinavait/My-first-project-OOP/releases/tag/v0.4.1)
Patobulinta `v0.4` versijos realizacija

* Atliekamas **konteinerių testavimas**: išmatuojama patobulintos `v0.3.1` realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
    * [std::vector](http://en.cppreference.com/w/cpp/container/vector)
    * [std::list](http://en.cppreference.com/w/cpp/container/list)

:heavy_exclamation_mark:  Tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl `v0.4.1` versijoje matuojami šie programoje atliekami žingsniai (patobulinta programos veikimo greičio (spartos) analizė):
- [x] duomenų nuskaitymas iš failų;
- [x] studentų rūšiavimas (dalijimas) į dvi grupes/kategorijas;
    
Testavimas atliekamas su tais pačiais failais, sudarytais iš 1 000, 10 000, 100 000, 1 000 000 įrašų. <br>
* Jei failas jau egzistuoja anksčiau direktorijoje sukurtame **"files/"** aplankale, programos veikimo greičio (spartos) analizė atliekama su anksčiau sugeneruotu failu. 
* Jei failas dar neegzistuoja, pirmiausia  failas sugeneruojamas, vartotojui į konsolę įvedant, kokį failą norima generuoti, ir tik tuomet vykdoma programos spartos analizė.

### Išvados
* Naudojant tiek `std::vector`, tiek `std::list` konteinerius duomenų nuskaitymo sparta yra panaši.
* List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.

# [v1.0 versija](https://github.com/evelinavait/My-first-project-OOP/tree/v1.0)

* Optimizuojama studentų rūšiavimo (skirstymo) į dvi kategorijas ("stupid" ir "smart") realizacija: t. y. `std::vector` ir `std::list` konteinerių tipams išmatuojama programos veikimo sparta, priklausomai nuo studentų skirstymo į dvi kategorijas strategijos:
  * **1 strategija**: Bendro "students" konteinerio (`vector` ir `list` tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "stupid" ir "smart". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame "students" ir viename iš suskaidytų ("stupid" arba "smart").
  * **2 strategija**: Bendro "students" konteinerio (`vector` ir `list`) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "stupid". Tokiu būdu, jei studentas yra nelaimingas "stupid", jį turime įkelti į naująjį "stupid" konteinerį ir ištrinti iš bendro "students" konteinerio. Po šio žingsnio "students" konteineryje liks vien tik protingi "smart".
* Ant vieno fiksuoto konteinerio - `vector` studentų rūšiavimo (dalijimo) procedūrai paspartinti, t. y. optimizuoti pritaikytas algoritmas `std::stable_partition`: visi elementai, kurių galutinis vidurkis > 5 eina prieš tuos, kurie netenkina sąlygos (galutinis vidurkis < 5).
* Parengta naudojimosi instrukcija, t. y. aprašyti pagrindiniai žingsniai. 
* Parengta įdiegimo instrukcija, t. y. sukurtas **cmake** `CMakeLists.txt` (bet kokios OS atveju).

### Išvados ###
* Naudojant 1 strategiją programos vykdymo greitis gana spartus, tačiau 1 strategija yra neefektyvi užimamos atminties atžvilgiu. Naudojant tiek `std::vector`, tiek `std::list` konteinerius duomenų nuskaitymo sparta yra panaši. List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.
* Atminties atveju 2 strategija efektyvesnė, tačiau dažni trynimai gali būti "skausmingi".

# My-second-project-OOP
Project No. 2 C++ Programming

# [v1.1 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.1)

Patobulinta 1-osios užduoties programos realizacija (`v1.0` versija)
- [x] Vietoje struktūros `struct Student`, jos pagrindu, vadovaujantis "gerosiomis praktikomis", sukuriama klasė `class Student`.
- [ ] Palyginama abiejų programų: naudojančios `struct` (ankstesnis darbas) ir naudojančios `class` tipą (dabartinė realizacija) sparta (veikimo laikas), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100 000 ir 1 000 000 dydžio failus
- [ ] Atliekama eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: `O1, O2, O3`.

> Programos veikimo greitis beveik nepriklauso nuo to, ar yra panaudota struktūra, ar klasė.
> Šiuo atveju tarp skirtingų flagų nėra didelio skirtumo. Tačiau, yra svarbu kompiliuoti su optimizacija, nes be jos programos veikimas yra labai lėtas.

# [v1.1.1 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.1.1)
Patobulinta `v1.1` versijos realizacija

- [x] Vietoje struktūros `struct Student`, jos pagrindu, vadovaujantis "gerosiomis praktikomis", sukuriama klasė `class Student`.
- [x] Palyginama abiejų programų: naudojančios `struct` (ankstesnis darbas) ir naudojančios `class` tipą (dabartinė realizacija) sparta (veikimo laikas), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100 000 ir 1 000 000 dydžio failus
- [x] Atliekama eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: `O1, O2, O3`.

# [v1.2 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.2)
Realizuojama "Rule of three":
I. Destructor
II. Copy constructor
III. Copy assignment (`operator=`)

Taip pat turimai `Student` klasei realizuojama įvesties/išvesties << operatorius.

# [v1.2.1 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.2.1)
Patobulinta `v1.2` versijos realizacija

Realizuojama "Rule of three":\
I. Destructor\
II. Copy constructor\
III. Copy assignment (`operator=`)

Taip pat turimai `Student` klasei realizuojama įvesties/išvesties << operatorius.

# [v1.5 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.5)
* Vietoj turimos `Student` klasės sukuriamos dvi: bazinė klasė, skirta bendrai aprašyti žmogų `Human` ir tuomet iš jos išvestinė (derived) klasę - `Student`.
* Žmogui `Human` skirta bazinė klasė yra abstrakčioji klasė, t. y. nėra galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių.

# [v1.5.1 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v1.5.1)
Patobulinta `v1.5` versijos realizacija

Nuo `v1.5.1` versijos užduotys atliekamos naudojantis **Visual Studio** programinės įrangos aplinka.

* Vietoj turimos `Student` klasės sukuriamos dvi: bazinė klasė, skirta bendrai aprašyti žmogų `Human` ir tuomet iš jos išvestinė (derived) klasę - `Student`.
* Priešingai nuo `v1.2.1` versijos sukurtas numatytasis (angl. default) `Student` klasės konstruktorius, patobulinta įvesties/išvesties << operatorių realizacija.
* `v1.5` versijoje žmogui `Human` skirta bazinė klasė buvo abstrakčioji klasė, todėl `v1.5.1` versijoje `Human` klasė patobulinta, t. y. nėra galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių.

# [v2.0 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v2.0)
Panaudojant Doxygen sukuriama dokumentacija, ji pateikiama kaip atskiras HTML katalogas.\
Norint pasiekti dokumentacijos puslapį, paleidžiamas `html` aplankale esantis `index.html` failas. Dokumentacijoje nurodomos klasės, jų hierarchija, klasėse apibrėžtų narių ir funkcijų sąrašai.

# [v2.0.1 versija](https://github.com/evelinavait/My-second-project-OOP/tree/v2.0.1)
Patobulinta `v2.0` versijos realizacija

Panaudojant Doxygen sukuriama dokumentacija, ji pateikiama kaip atskiras HTML katalogas. v2.0 versijoje pateikta dokumentacija papildyta komentarais, išsamia ataskaita.\
Norint pasiekti dokumentacijos puslapį, paleidžiamas `html` aplankale esantis `index.html` failas. Dokumentacijoje nurodomos klasės, jų hierarchija, klasėse apibrėžtų narių ir funkcijų sąrašai.

## Įdiegimo instrukcija ##
1. Parsisiųsti norimą programos versijos kodą iš Releases;
2. Kodą sukompiliuoti per komandinę eilutę arba pasirinktą IDE.
Naudojant `CMakeLists.txt` ir komandas vykdant darbinėje direktorijoje, kurioje talpinamas parsisiųstas programos versijos kodas:
```
cmake CMakeLists.txt
cmake --install.
cmake --build .
copy files\ Debug\
Debug\Students-v2-0.exe
```
## Naudojimosi instrukcija ##
1. Įvesties/išvesties << operatorių realizacija. Į konsolę įvedamas studento vardas, pavardė, įvedami 5-i namų darbų (ND) pažymiai, studento egzamino pažymys. Taip konsolėje realizuojant išvesties operatorių, atspausdinamas vardas, pavardė, ND pažymiai, egzamino pažymys ir galutinis įvertinimas.
2. Toliau į konsolę įvedamas studentų skaičius (n), t. y. kokį failą norima generuoti. Taip sugeneruojami atsitiktiniai studentų sąrašų failai, kurių (preliminarioje) struktūroje generuojami Vardai ir Pavardės, kaip pvz. `Vardas1 Pavarde1`, `Vardas2 Pavarde2` ir t.t. Taip pat sugeneruojami atsitiktiniai namų darbų ir egzamino įvertinimų balai (`ND1 ND2 ND3 ND4 ND5 Egzaminas`).
3. Atliekama programos veikimo greičio (spartos) analizė. <br>
3.1 Jei failas jau egzistuoja anksčiau direktorijoje sukurtame **"files/"** aplankale, programos veikimo greičio (spartos) analizė atliekama su anksčiau sugeneruotu failu. <br>
3.2 Jei failas dar neegzistuoja, pirmiausia  failas sugeneruojamas, vartotojui į konsolę įvedant, kokį failą norima generuoti, ir tik tuomet vykdoma programos spartos analizė.

## Testų metu naudoto kompiuterio parametrai: ##

* Intel(R) Core(TM) i5-4200M CPU @ 2.50GHz 2.50 GHz
* 4GB RAM
* Windows 7 Ultimate; 64 bitų operacinė sistema
