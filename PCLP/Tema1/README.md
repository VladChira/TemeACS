
# Tema 1 - Calculator

## Cerinta

Pentru aceasta tema va trebui sa implementati un calculator care sa faca operatii aritmetice. Programul citeste de la tastatura o expresie aritmentica si afiseaza rezultatul acestei expresii. Formatul de citire a expresiei de la tastatura este urmatorul: se citeste un numar N, apoi N numere reale, iar in final se citesc N-1 operatii. O operatie este reprezentata de un caracter si poate avea valorile: ' ', '-', '*', '/'. Astfel, urmatorul input: 
Exemplu utilizare: 

```
4    // N = 4
3    // operand 1
3    // operand 2
4    // operand 3
5    // operand 4
 */  // N-1 = 3 operatii
```

Va fi interpretat ca: “3 3*4/5”. 

### Task 1
Pentru prima cerinta va trebui sa implementati citirea unei expresii si evaluarea acesteia, neglijand precedenta operatorilor. Astfel, pentru expresia “3 3*4/5”, veti evalua operatiile in ordinea in care apar: 3 3*4/5 6*4/5 = 24/5 = 4.8 .

### Task 2
Pentru a doua cerinta va trebui sa implementati citirea unei expresii si evaluarea acesteia tinand cont si de precendenta operatorilor. Astfel, pentru expresia “3 3*4/5”, veti evalua operatiile tinand cont de faptul ca operatiile '*' si '/' au precedenta mai mare fata de ' ' si '-'. In consecinta, pentru acesta sarcina, rezultatul expresiei anterioare va fi: 3 3*4/5 = 3 12/5 = 3 2.4 = 5.4 .

Mai mult, va trebui sa implementeti un nou operator, operatorul `#`. Operatorul `#` este definit astfel: a#b = (a b)*(a b). Operatorul `#` are precedenta mai mare ca ` `/ `-`, dar mai mica ca `*` /`/`.




## Cerinta

## Rezolvare

### Task 1 - Evaluarea expresiei fara ordinea operatiilor
Operanzii si operatorii se citesc intr-un vector, respectiv intr-un sir de caractere. Prin rasturnare, ele pot forma un fel de stiva. Pentru a evalua expresia
fara a tine cont de ordinea operatiilor, se elimina cate doua numere din stiva operanzilor si un operator din stiva operatorilor. Rezultatul se pune inapoi pe stiva
si se repeta cat timp mai exista operatori cu care putem efectua operatii. La final, varful stivei contine rezultatul.

### Task 2 - Evaluarea expresiei cu ordinea operatiilor si un operator definit de utilizator
Se bazeaza pe acelasi principiu, dar introducerea precedentei operatorilor face procesul mai complex. Pentru inceput, se 'reintroduc' operatorii la locul lor in
operatie (in notatia infix , ex 3+3*4/5). Totusi, memorarea intregii expresii nu se poate face deoarece contine si numere reale si caractere, asa ca am optat sa lucrez doar cu vectorul de numere. Am observat ca in 3+3*4/5, operatorii se afla pe pozitie impara deci in vector ar putea fi inlocuiti cu un numar arbitrar, aici 0. Asadar
3+3*4/5 ---> 3 0 3 0 4 0 5
Cand am nevoie de un operator, il caut in sirul citit initial.
Pentru evaluarea expresiei, se parcurge element cu element.
Daca se intalneste un numar, se adauga in stiva operanzilor.
Daca se intalneste un operator, se tine cont de precedenta: nu este adaugat in stiva pana cand toate operatiile cu precedenta mai mare sau egala au fost deja efectuate De exemplu, daca in varful stivei se afla un '+', iar operatorul
curent este '*', atunci se poate adauga in stiva. Cat timp precedenta este respectata, din stiva operanzilor se scot doua valori, iar din stiva operatorilor un operator.
Rezultatul calcului este pus in stiva s.a.m.d.

La final, dupa parcurgerea vectorului, mai raman in stive numere si operatori ce trebuie evaluati. Totusi, la final este imposibil sa mai fie necesara ordinea operatiilor
asa ca se evalueaza in ordine, ca la task-ul 1.
