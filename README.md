# My-first-project-OOP
Project C++ Programming


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
