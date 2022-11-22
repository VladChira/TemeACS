

# Tema 0 - Trick Or Treat

## Cerinta

Scrieți un program care citește de la standard input (tastatură) un număr natural, N. Pentru toate valorile din intervalul [1, N], programul va afișa, separate printr-un spațiu ( ): 

- cuvântul Trick dacă valoarea curentă este divizibilă cu 7
- cuvântul Treat dacă valoarea curentă este divizibilă cu 11
- cuvântul TrickOrTreat dacă valoarea curentă este divizibilă cu 7 și cu 11
- valoarea curentă, atunci când aceasta nu este divizibilă cu 7 sau 11


Exemplu utilizare: 

```
./tema0
Introduceti valoarea numarului natural N:
11
1 2 3 4 5 6 Trick 8 9 10 Treat
```

## Rezolvare
Pentru fiecare numar din intervalul [1,n] se initializeaza un sir de caractere cu null. Daca este divizibil cu 7 se concateneaza Trick, daca este divizibil si cu 7 si cu 11 se concateneaza Or iar daca este divizibil cu 11 se concateneaza Treat. Daca sirul de caractere ramane gol in urma acestor operatii, atunci nu este divizibil cu niciunul si se afiseaza numarul.
