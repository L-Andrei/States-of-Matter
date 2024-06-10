#include <iostream>
#include <cmath>

class PontoEbulicao {
private:
    double a, b, c;

public:
    PontoEbulicao(double a_coef, double b_coef, double c_coef) {
        a = a_coef;
        b = b_coef;
        c = c_coef;
    }

    double calcular(double pressao) {

        return b / (a - log10(pressao)) - c;
    }
};