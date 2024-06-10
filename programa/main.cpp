#include <iostream>
#include "substancia.h"
#include "ambiente.h"

int main() {
    Substancia agua(1.0, 18.015, 1000.0, 2260.0 * 1000.0, 334 * 1000.0); 
    double ponto_ebulicao = agua.calculaPontoEbulicao();
    std::cout << "O ponto de ebulição da água a pressão atmosférica é: " << ponto_ebulicao 
    << " K" << std::endl;

    return 0;
}