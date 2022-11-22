// -------FIZZBUZZ Halloween Edition-------
#include <stdio.h>
#include <string.h>
#define MAX_S 13
int main() {
    int n = 0;
    char s[MAX_S] = "";

    printf("Introduceti valoarea numarului natural N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        snprintf(s, sizeof(s), "%s", "\0"); // glorified strcpy

        if (i % 7 == 0)
            snprintf(s + strlen(s), 6 , "%s", "Trick"); // glorified strcat

        if (i % 7 == 0 && i % 11 == 0)
            snprintf(s + strlen(s), 3, "%s", "Or");

        if (i % 11 == 0)
            snprintf(s + strlen(s), 6, "%s", "Treat");

        if (s[0] == '\0' )
            printf("%d ", i);
        else
            printf("%s ", s);
    }
    printf("\n");
    return 0;
}
