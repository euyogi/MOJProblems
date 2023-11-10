#include <stdio.h>

void printarMatriz(int N, int M[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0)
                printf("%d", M[i][j]);
            else
                printf(" %d", M[i][j]);
        }
        printf("\n");
    }
}

int eliminar(int N, int M[N][N]) {
    int eliminamos_algo = 0;

    for (int i = 0; i < N; ++i) {
        int apenas_uns = 1;
        for (int j = 0; j < N; ++j) {
            if (M[i][j] == 0) {
                apenas_uns = 0;
                break;
            }
        }

        if (apenas_uns) {
            for (int j = 0; j < N; ++j)
                M[i][j] = 0;

            eliminamos_algo = 1;
        }
    }

    return eliminamos_algo;
}

void cair(int N, int M[N][N]) {
    int p;
    for (int i = 0; i < N; ++i) {
        p = N - 1;
        for (int j = N - 1; j >= 0; --j) {
            if (M[j][i] == 1) {
                M[j][i] = 0;
                M[p][i] = 1;
                --p;
            }
        }
    }

    printf("\n");
    printarMatriz(N, M);
}

int main() {
    int N;
    scanf("%d", &N);

    int M[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &M[i][j]);
    }

    int terminou = 0;

    eliminar(N, M);
    printarMatriz(N, M); // P
    cair(N, M); // \n P

    while (!terminou) {
        if (eliminar(N, M) == 0)
            break;

        printf("\n"); // \n
        printarMatriz(N, M); // P
        cair(N, M); // \n P
    }
}
