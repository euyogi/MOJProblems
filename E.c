void printarMatriz(int** M, int N) {
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

int eliminar(int** M, int N) {
    int eliminamos_algo = -1;

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

            eliminamos_algo = 0;
        }
    }

    printarMatriz(M, N);
    return eliminamos_algo;
}

void cair(int** M, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            
        }
    }

    printarMatriz(M, N);
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

    eliminar(M, N);
    cair(M, N);

    while (!terminou) {
        if (eliminar(M, N) == -1)
            break;

        cair(M, N);
    }
}
