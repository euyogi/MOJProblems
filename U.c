#include <stdio.h>

int main() {
    int R;
    
    int dia = 1;
    int max_nota;
    int min_cod;
    while (scanf("%d", &R) != EOF) {
        for (int i = 0; i < R; ++i) {
            int cod, nota;
            scanf("%d %d", &cod, &nota);
            
            if (i == 0) {
                max_nota = nota;
                min_cod = cod;
            }
            else if (nota > max_nota) {
                max_nota = nota;
                min_cod = cod;
            }
            else if (nota == max_nota && cod < min_cod)
                min_cod = cod;
        }
        
        printf("Dia %d\n", dia);
        printf("%d\n\n", min_cod);
        
        ++dia;
    }
}
