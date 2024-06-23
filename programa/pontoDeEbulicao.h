#ifndef PONTODEEBULICAO_H
#define PONTODEEBULICAO_H

class PontoDeEbulicao{

    private:
    double a; 
    double b;
    double c;

    public:
    PontoDeEbulicao();
    PontoDeEbulicao(double a_coef, double b_coef, double c_coef);
    double calcular(double pressao);
    
};
#endif