#include <iostream>

class PontoFusao {
private:
    double delta_H_vap; 
    double delta_S_fus; 

public:
    PontoFusao(double calor_vaporizacao, double entropia_fusao) {
        delta_H_vap = calor_vaporizacao;
        delta_S_fus = entropia_fusao;
    }

    double calcular() {
        // Calculando o ponto de fusão usando a regra de Trouton
        return (delta_H_vap / delta_S_fus) - 273.15; // Convertendo de Kelvin para Celsius
    }
};
