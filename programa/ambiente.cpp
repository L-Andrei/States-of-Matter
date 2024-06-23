#include <iostream>
#include <cmath>
#include "ambiente.h"

Ambiente::Ambiente(double pressao, double temp) : p(pressao), t(temp) {}

double Ambiente::getPressao() const {
    return p; // Pressão inicial
}

double Ambiente::getTemperatura() const{
    return t; // temperatura atual do ambiente;
}

double Ambiente::conversor(){ // COnverte a pressão de atm para mmhg.
    double pressao = p * 760;
    return pressao;
}