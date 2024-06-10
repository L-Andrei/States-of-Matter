#include <cmath>
#include "ambiente.h"

const float Ambiente::M = 0.029;
const float Ambiente::g = 9.81;  
const float Ambiente::R = 8.314; 

Ambiente::Ambiente(float pressao, float temp) : p(pressao), t(temp) {}

Ambiente::Ambiente(float temp, float altura, float forca) : t(temp) {
    p = getP2(altura); // Calcula a pressão com base na altura
}

float Ambiente::getP1() const {
    return p; // Pressão inicial
}

float Ambiente::getP2(float altura) const {
    return p * exp(-M * g * altura / (R * t)); // Calcula a pressão a uma determinada altura
}
