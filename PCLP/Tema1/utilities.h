#include <stdio.h>
#include <string.h>
#define NMAX 10000
#define PRECEDENTA_1 10
#define PRECEDENTA_2 15
#define PRECEDENTA_3 20

void insert_in_array(double a[], int *n, int poz, double x) {
    for (int i = *n - 1; i >= poz; i--) {
        a[i + 1] = a[i];
    }
    a[poz] = x;
    (*n)++;
}

int nivel_precedenta(char ch) {
    // Alegem arbitrar ca +- sa aiba precedenta 10
    // Iar */ sa aiba precedenta 20
    // Task 3: # are precedenta intre +- si */, adica 15
    if (ch == '+' || ch == '-') {
        return PRECEDENTA_1;
    }

    if (ch == '#') {
        return PRECEDENTA_2;
    }

    if (ch == '*' || ch == '/') {
        return PRECEDENTA_3;
    }
    printf("Eroare fatala la precedenta\n");
    return -1;
}


void reverse_array(double a[], int n) {
    double aux[NMAX];

    for (int i = 0; i < n; i++) {
        aux[n - i - 1] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = aux[i];
    }
}

void reverse_string(char *s) {
    int l = (int)strlen(s);
    char aux = '\0';
    for (int i = 0; i < l / 2; i++) {
        aux = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = aux;
    }
}

int citire(double operanzi[], char *operatori) {
    int N = 0;
    printf("Introduceti nr de operanzi, valorile lor si apoi operatorii: ");
    scanf("%d", &N);
    if (N == 0) {
        return 0;
    }

    if (N == 1) {
        int ch = 0;
        scanf("%lf", &operanzi[0]);
        ch = getchar();
        ch++;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%lf\n", &operanzi[i]);
    }
    fgets(operatori, N, stdin);
    return N;
}

double evaluare(double a, double b, char op) {
    switch (op) {
        case '+':
            return (double)a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '#':
            return (a + b) * (a + b);
        default:
            printf("Eroare fatala la evaluare\n");
            return -1;
    }
}
