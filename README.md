# My-first-project-OOP #
Project C++ Programming

# v0.3 versija #
* Sugeneruojami atsitiktiniai studentų sąrašų failai, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000 įrašų. Vardai ir Pavardės generuojami "šabloniniai", kaip pvz. `Vardas1 Pavarde1`, `Vardas2 Pavarde2` ir t.t.
* Studentai surūšiuojami (padalinami) į dvi kategorijas:
  * Studentai, kurių galutinis balas < 5.0 - nelaimingi
  * Studentai, kurių galutinis balas >= 5.0 - protingi
* Surūšiuoti studentai išvedami į du naujus failus `1000-studentai.txt`
* Atliekama programos veikimo greičio (spartos) analizė: t.y. išmatuojama programos sparta išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
    - [x] failų kūrimą;
    - [ ] duomenų nuskaitymą iš failų;
    - [x] rūšiavimą didėjimo tvarka, naudojant sort funkciją
    - [x] studentų dalijimą į dvi grupes/kategorijas;
    - [x] surūšiuotų studentų išvedimą į du naujus failus.

|Įrašai|Failų kūrimas|Rūšiavimas didėjimo tvarka |Dalijimas į dvi grupes|Išvedimas į nelaimingi.txt |  Išvedimas į protingi.txt
|---|----:|----|---|---
|1000 įrašų| 0.10|0.005|0 |       0|2017-01-01 03:04:05+0900|
|10000 įrašų|-2.23|0.062 |0.004|        |2017-12-23 12:34:51+0900|
|100000 įrašų| 0.00|0.884 |0.056 |Infinity|2017-03-03 22:44:55+0900|
|1000000 įrašų|-9.90|10.739|0.614|     NaN|2017-01-01 00:00:00+0900|

![285697313_627629259060279_957838069182607771_n](https://user-images.githubusercontent.com/72965991/195760793-ea7b354f-496f-4786-8d20-58b0f01ff2e5.png)


## Testų metu naudoto kompiuterio parametrai: ##

* Intel(R) Core(TM) i5-4200M CPU @ 2.50GHz 2.50 GHz
* 4GB RAM
* Windows 7 Ultimate; 64 bitų operacinė sistema
