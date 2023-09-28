#include <stdio.h>

struct Ponto {
    int x, y;
};

int main() {
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    
    struct Ponto a = { 1, 1 };
    struct Ponto b = { N, M };
    
    struct Ponto ocorreu_em;
    int passo = -1;
    char prof_que_saiu = -1;
    
    for (int i = 0, A, B; i < P; ++i) {
        scanf("%d %d", &A, &B);
        
        if (passo != -1)
            continue;
        
        if (i == 0 && a.x == b.x && a.y == b.y) {
            ocorreu_em.x = a.x;
            ocorreu_em.y = a.y;
            
            passo = 1;
        }
        
        switch (A) {
            case 1:
                ++a.y;
                break;
            case 2:
                --a.y;
                break;
            case 3:
                ++a.x;
                break;
            case 4:
                --a.x;
                break;
        }
        
        switch (B) {
            case 1:
                ++b.y;
                break;
            case 2:
                --b.y;
                break;
            case 3:
                ++b.x;
                break;
            case 4:
                --b.x;
                break;
        }
        
        if (a.x < 1 || a.x > N || a.y < 1 || a.y > M)
            prof_que_saiu = 'A';
        else if (b.x < 1 || b.x > N || b.y < 1 || b.y > M)
            prof_que_saiu = 'B';
            
        if (a.x == b.x && a.y == b.y || prof_que_saiu != -1) {
            ocorreu_em.x = a.x;
            ocorreu_em.y = a.y;
            
            if (b.x < 1 || b.x > N || b.y < 1 || b.y > M) {
                ocorreu_em.x = b.x;
                ocorreu_em.y = b.y;
            }
            
            passo = i + 1;
        }
    }
    
    if (passo == -1)
        printf("Nao se encontraram\n");
    else if (prof_que_saiu != -1)
        printf("P%c saiu na posicao (%d,%d) no passo %d\n", prof_que_saiu, ocorreu_em.x, ocorreu_em.y, passo);
    else
        printf("Encontraram-se na posicao (%d,%d) no passo %d\n", ocorreu_em.x, ocorreu_em.y, passo);
    
}
