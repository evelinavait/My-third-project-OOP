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
* Atliekamas **konteinerių testavimas**: išmatuojama patobulintos `v0.3.1` realizacijos veikimo sparta priklausomai nuo naudojamo vieno iš dviejų konteinerių:
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

Apačioje pateikiamas CPU naudojimas ir retrospektyva, atminties parametrai, atliekant programos veikimo greičio (spartos) analizę su failu, sudarytu iš 1 000 000 įrašų.

![CPU_1000000](https://user-images.githubusercontent.com/72965991/198593227-25df8dd9-f475-451c-970b-8e126354bbad.png)

# v0.4.1 versija
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

![v041_1000](https://user-images.githubusercontent.com/72965991/201263423-5aab8de3-f3ae-4578-826a-48ae5afe3e62.png)
![v041_1_1000](https://user-images.githubusercontent.com/72965991/201263444-e2f400ac-bffc-4b26-92d7-79c153425a7b.png)
![v041_10000](https://user-images.githubusercontent.com/72965991/201263466-6770fc5c-eeb1-420c-8b3a-98846eedf979.png)
![v041_100000](https://user-images.githubusercontent.com/72965991/201263475-77fd67a4-5512-482e-82b0-503b495ec6a2.png)
![v041_1000000](https://user-images.githubusercontent.com/72965991/201263478-cbeade98-a0a4-4d0d-ae7d-cee6ba4b9ca3.png)

Apačioje pateikiamas CPU naudojimas ir retrospektyva, atminties parametrai, atliekant programos veikimo greičio (spartos) analizę su failu, sudarytu iš 1 000 000 įrašų.

<img src="https://user-images.githubusercontent.com/72965991/201263671-5cc46678-7983-42ea-ae2c-4b092713254d.png" width="650"> <img src="https://user-images.githubusercontent.com/72965991/201265404-00877f35-2ecd-49b0-b698-10a6fabada39.png" height="280">

### Išvados
* Naudojant tiek `std::vector`, tiek `std::list` konteinerius duomenų nuskaitymo sparta yra panaši.
* List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.

# v1.0 versija

* Optimizuojama studentų rūšiavimo (skirstymo) į dvi kategorijas ("stupid" ir "smart") realizacija: t. y. `std::vector` ir `std::list` konteinerių tipams išmatuojama programos veikimo sparta, priklausomai nuo studentų skirstymo į dvi kategorijas strategijos:
  * **1 strategija**: Bendro "students" konteinerio (`vector` ir `list` tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "stupid" ir "smart". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame "students" ir viename iš suskaidytų ("stupid" arba "smart").
  * **2 strategija**: Bendro "students" konteinerio (`vector` ir `list`) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "stupid". Tokiu būdu, jei studentas yra nelaimingas "stupid", jį turime įkelti į naująjį "stupid" konteinerį ir ištrinti iš bendro "students" konteinerio. Po šio žingsnio "students" konteineryje liks vien tik protingi "smart".
* Ant vieno fiksuoto konteinerio - `vector` studentų rūšiavimo (dalijimo) procedūrai paspartinti, t. y. optimizuoti pritaikytas algoritmas `std::stable_partition`: visi elementai, kurių galutinis vidurkis > 5 eina prieš tuos, kurie netenkina sąlygos (galutinis vidurkis < 5).
* Parengta naudojimosi instrukcija, t. y. aprašyti pagrindiniai žingsniai. 
* Parengta įdiegimo instrukcija, t. y. sukurtas **cmake** `CMakeLists.txt` (bet kokios OS atveju).

![v1_1000](https://user-images.githubusercontent.com/72965991/201288131-2f6e34c9-58b0-4ddc-8449-618f7ead5dd9.png)
![v1_10000](https://user-images.githubusercontent.com/72965991/201287370-44ea3516-6a78-4547-8e4f-392cc694744c.png)
![v1_100000](https://user-images.githubusercontent.com/72965991/201286588-6edc7a1e-3e55-46e6-8dec-1cc5dcb2df0a.png)
![v1_1000000](https://user-images.githubusercontent.com/72965991/201286849-4fc653fa-be2d-4b2c-b968-6e34513320d0.png)

Žemiau pateikiamas CPU naudojimas ir retrospektyva, atminties parametrai, atliekant programos veikimo greičio (spartos) analizę su failu, sudarytu iš 1 000 000 įrašų.

<img src="https://user-images.githubusercontent.com/72965991/201289257-f8f0b3a4-1941-4c6d-9b51-2e6b3c35ff68.png" width="650">  <img src="https://user-images.githubusercontent.com/72965991/201290349-3975770c-4545-4b7b-ac82-cb74ef0bfed1.png" height="280">

### Išvados ###
* Naudojant 1 strategiją programos vykdymo greitis gana spartus, tačiau 1 strategija yra neefektyvi užimamos atminties atžvilgiu. Naudojant tiek `std::vector`, tiek `std::list` konteinerius duomenų nuskaitymo sparta yra panaši. List'ų struktūra sudėtingesnė, todėl skirstant studentus į dvi grupes/kategorijas, jie yra lėtesni nei vektoriai.
* Atminties atveju 2 strategija efektyvesnė, tačiau dažni trynimai gali būti "skausmingi".

# v1.1 versija

Patobulinta 1-osios užduoties programos realizacija (`v1.0` versija)
- [x] Vietoje struktūros `struct Student`, jos pagrindu, vadovaujantis "gerosiomis praktikomis", sukuriama klasė `class Student`.
- [ ] Palyginama abiejų programų: naudojančios `struct` (ankstesnis darbas) ir naudojančios `class` tipą (dabartinė realizacija) sparta (veikimo laikas), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100 000 ir 1 000 000 dydžio failus
- [ ] Atliekama eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: `O1, O2, O3`.

> Programos veikimo greitis beveik nepriklauso nuo to, ar yra panaudota struktūra, ar klasė.
> Šiuo atveju tarp skirtingų flagų nėra didelio skirtumo. Tačiau, yra svarbu kompiliuoti su optimizacija, nes be jos programos veikimas yra labai lėtas.

# v1.2 versija
Realizuojama "Rule of three":\
I. Destructor\
II. Copy constructor\
III. Copy assignment (`operator=`)

Taip pat turimai `Student` klasei realizuojama įvesties/išvesties << operatorius.

# v1.2.1 versija
Realizuojama "Rule of three":\
I. Destructor\
II. Copy constructor\
III. Copy assignment (`operator=`)

Taip pat turimai `Student` klasei realizuojama įvesties/išvesties << operatorius.

# v1.5 versija
* Vietoj turimos `Student` klasės sukuriamos dvi: bazinė klasė, skirta bendrai aprašyti žmogų `Human` ir tuomet iš jos išvestinė (derived) klasę - `Student`.
* Žmogui `Human` skirta bazinė klasė yra abstrakčioji klasė, t. y. nėra galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių.

# v2.0 versija
Panaudojant Doxygen sukuriama dokumentacija, ji pateikiama kaip atskiras HTML katalogas.\
Norint pasiekti dokumentacijos puslapį, paleidžiamas `html` aplankale esantis `index.html` failas. Dokumentacijoje nurodomos klasės, jų hierarchija, klasėse apibrėžtų narių ir funkcijų sąrašai.

## diegimo instrukcija ##
1. Parsisiųsti norimą programos versijos (v1.0) kodą iš Releases;
2. Kodą sukompiliuoti per komandinę eilutę arba pasirinktą IDE.
Naudojant `CMakeLists.txt`:
```
cmake .
cmake --build .
```
## Naudojimosi instrukcija ##
1. Į konsolę įvedamas studentų skaičius (n), t. y. kokį failą norima generuoti. Taip sugeneruojami atsitiktiniai studentų sąrašų failai, kurių (preliminarioje) struktūroje generuojami Vardai ir Pavardės, kaip pvz. `Vardas1 Pavarde1`, `Vardas2 Pavarde2` ir t.t. Taip pat sugeneruojami atsitiktiniai namų darbų ir egzamino įvertinimų balai (`ND1 ND2 ND3 ND4 ND5 Egzaminas`).
2. Atliekama programos veikimo greičio (spartos) analizė. <br>
2.1 Jei failas jau egzistuoja anksčiau direktorijoje sukurtame **"files/"** aplankale, programos veikimo greičio (spartos) analizė atliekama su anksčiau sugeneruotu failu. <br>
2.2 Jei failas dar neegzistuoja, pirmiausia  failas sugeneruojamas, vartotojui į konsolę įvedant, kokį failą norima generuoti, ir tik tuomet vykdoma programos spartos analizė.

## Testų metu naudoto kompiuterio parametrai: ##

* Intel(R) Core(TM) i5-4200M CPU @ 2.50GHz 2.50 GHz
* 4GB RAM
* Windows 7 Ultimate; 64 bitų operacinė sistema
