#include <stdio.h>

struct tipoBanda {
    char nome[80];
    int ano;
};

struct tipoShow {
    char nome[80];
    int qtd;
    struct tipoBanda bandas[100];
};

int str_iguais(char *str_1, char* str_2) {
    int i;
    for (i = 0; str_1[i] != '\0'; ++i) {
        if (str_2[i] == '\0' || str_1[i] != str_2[i])
            return 0;
    }

    return str_2[i] == '\0';
}

void copiar_str(char *target, char* dest) {
    int i;
    for (i = 0; target[i] != '\0'; ++i)
        dest[i] = target[i];
    target[i] = '\0';
}

void pesquisarNomeBanda(char pesquisa[80], struct tipoShow shows[50], int n) {
    char show[80];
    int ano, achou = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < shows[i].qtd; ++j) {
            if (str_iguais(shows[i].bandas[j].nome, pesquisa)) {
                copiar_str(shows[i].nome, show);
                ano = shows[i].bandas[j].ano;
                printf("%s : ano %d\n", show, ano);
                achou = 1;
                break;
            }
        }
    }

    if (!achou)
        printf("Banda nao cadastrada\n");
}

int main() {
    struct tipoShow shows[50] = {
        {"Porao do rock", 3, {
            {"Ursa", 2018}, {"BellRays", 2007}, {"Estamira", 2010}
            }
        },
        
        {"Lollapalooza", 5, {
            {"Foo Fighters"}
            }
        }, {"Rock in Rio", 2}}
}
