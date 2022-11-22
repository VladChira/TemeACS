#include "utilities.h"

int main() {
    double operanzi[NMAX] = {0};
    char operatori[NMAX] = "";

    int N = citire(operanzi, operatori);
    if (N == 0) {
        printf("%f\n", 0.0);
        return 0;
    }
    if (N == 1) {
        printf("%f\n", operanzi[0]);
        return 0;
    }

    // Reconstruim expresia in forma infix, punand 0 in locul operatorilor
    int operanzi_size = N;
    for (int i = 0; i < operanzi_size; i++) {
        if (i % 2 == 1) {
            insert_in_array(operanzi, &operanzi_size, i, 0);
        }
    }

    double stiva_operanzi[NMAX] = {0};
    char stiva_operatori[NMAX] = "";
    int top_operanzi = -1, top_operatori = -1, operator_curent = 0;
    for (int i = 0; i < operanzi_size; i++) {
        if (i % 2 == 0) {
            // Am dat de un operand, se adauga in stiva operanzilor
            stiva_operanzi[++top_operanzi] = operanzi[i];
        }
        if (i % 2 == 1) {
            // Am dat de un operator. Care?
            char op = operatori[operator_curent++];

            // Trebuie verificat ce este in varful stivei operatorilor
            // Cat timp stiva nu este goala si varful stivei are precedenta mai mare
            while (top_operatori != -1) {
                int nivel_precedenta_top = 0, nivel_precedenta_operator = 0;
                nivel_precedenta_operator = nivel_precedenta(op);
                nivel_precedenta_top = nivel_precedenta(stiva_operatori[top_operatori]);
                if (nivel_precedenta_top < nivel_precedenta_operator) {
                    break;
                }

                // Se scot doi operanzi si un operator si se calculeaza
                double a = stiva_operanzi[top_operanzi--];
                double b = stiva_operanzi[top_operanzi--];
                char operator = stiva_operatori[top_operatori--];
                double rezultat = evaluare(b, a, operator);  // Obs: ordinea conteaza

                // printf("%f %c %f = %f \n\n", b, operator, a, rezultat);

                // Rezultatul se pune in stiva
                stiva_operanzi[++top_operanzi] = rezultat;
            }
            stiva_operatori[++top_operatori] = op;
        }
    }
    // Expresia infix este parcursa dar mai raman in stive operatii neefectuate
    while (top_operatori != -1) {
        double a = stiva_operanzi[top_operanzi--];
        double b = stiva_operanzi[top_operanzi--];
        char operator = stiva_operatori[top_operatori--];
        double rezultat = evaluare(b, a, operator);
        stiva_operanzi[++top_operanzi] = rezultat;
    }
    printf("Rezultatul este %f\n", stiva_operanzi[top_operanzi]);
    return 0;
}
