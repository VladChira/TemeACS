#include "utilities.h"

int main() {
    double operanzi[NMAX] = {0};
    char operatori[NMAX] = "";

    int N = citire(operanzi, operatori);
    if (N == 0) {
        // Caz special
        printf("%f\n", 0.0);
        return 0;
    }
    if (N == 1) {
        // Caz special
        printf("%f\n", operanzi[0]);
        return 0;
    }

    reverse_array(operanzi, N);
    reverse_string(operatori);
    int top_operanzi = N - 1, top_operatori = N - 2;
    while (top_operatori != -1) {
        double a = operanzi[top_operanzi--];
        double b = operanzi[top_operanzi--];
        char op = operatori[top_operatori--];
        double rezultat = evaluare(a, b, op);
        operanzi[++top_operanzi] = rezultat;
    }
    printf("Fara a tine cont de ordinea operatiilor, rezultatul este %f\n", operanzi[top_operanzi]);
    return 0;
}
