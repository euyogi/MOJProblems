#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; ++i) {
        int Pa, Pb;
        double Ia, Ib;
        scanf("%d %d %lf %lf", &Pa, &Pb, &Ia, &Ib);
        
        int j;
        for (j = 1; j <= 101; ++j) {
            Pa *= 1 + Ia * 0.01;
            Pb *= 1 + Ib * 0.01;
            
            if (Pa > Pb)
                break;
        }
        
        if (j > 100)
            printf("Mais de 1 seculo.\n");
        else
            printf("%d anos.\n", j);
    }
}
