#include <stdio.h>

double fogo(int nivel) {
    switch (nivel) {
    case 1:
        return 2.0;
    case 2:
        return 3.0;
    case 3:
        return 5.0;
    default:
        return -1;
    }
}

double agua(int nivel) {
    switch (nivel) {
    case 1:
        return 1.0;
    case 2:
        return 2.5;
    case 3:
        return 4.0;
    default:
        return -1;    
    }
}

double terra(int nivel) {
    switch (nivel) {
    case 1:
        return 2.5;
    case 2:
        return 5.5;
    case 3:
        return 7.0;
    default:
        return -1;
    }
}

double calculaVantagem(int tipoPlayer, int tipoCPU) {
    double vantagens[3][3] = {
        {1.0, 0.5, 2.0},
        {2.0, 1.0, 0.5},
        {0.5, 2.0, 1.0}
    };

    return vantagens[tipoPlayer - 1][tipoCPU - 1];
}

double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU) {
    switch (tipoPlayer) {
        case 1:
            return 100 * fogo(nivelPlayer) * calculaVantagem(tipoPlayer, tipoCPU) - defesaCPU;
        case 2:
            return 100 * agua(nivelPlayer) * calculaVantagem(tipoPlayer, tipoCPU) - defesaCPU;
        case 3:
            return 100 * terra(nivelPlayer) * calculaVantagem(tipoPlayer, tipoCPU) - defesaCPU;
        default:
            return -1;
    }
}

int main() {
    printf("%lf\n", agua(2));
    printf("%lf\n", fogo(2));
    printf("%lf\n", calculaVantagem(1, 3));
    printf("%lf\n", calculaVantagem(2, 2));
    printf("%lf\n", calculaDano(1, 1, 2, 73.4));
    printf("%lf\n", calculaDano(1, 3, 3, 1475.892));
}//100.0*2.0*0.5*
