#include <iostream>
#include <cmath>
#include "pontoDeEbulicao.h"

PontoDeEbulicao::PontoDeEbulicao(double a_coef, double b_coef, double c_coef) {
    a = a_coef;
    b = b_coef;
    c = c_coef;
}

PontoDeEbulicao::PontoDeEbulicao(){
    a = 0;
    b = 0;
    c = 0;
}

double PontoDeEbulicao::calcular(double pressao) { // Calcula o ponto de ebulição.
    if(a == 0 && b == 0 && c == 0){
        return 0;
    }else{
        return b / (a - log10(pressao)) - c;
    }    
}

/* Exemplo de coeficientes:

benzeno: a = 6.90565, b = 1211.033, c = 220.79;
água: a = 8.07131, b = 1730.63, c = 233.426;

*/