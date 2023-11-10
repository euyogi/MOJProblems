#include <stdio.h>

int str_iguais(char *str_1, char* str_2) {
    int i;
    for (i = 0; str_1[i] != '\0'; ++i) {
        if (str_2[i] == '\0' || str_1[i] != str_2[i])
            return 0;
    }

    return str_2[i] == '\0';
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    char palavras[N][81];
    for (int i = 0; i < N; ++i) 
        scanf("%s", palavras[i]);

    for (int i = 0; i < P; ++i) {
        char palavra[81];
        scanf("%s", palavra);

        for (int j = 0; j < N; ++j) {
            if (str_iguais(palavra, palavras[j]) == 1) {
                printf("1\n");
                return 0;
            }
        }
    }

    printf("0\n");
}
