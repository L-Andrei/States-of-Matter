#ifndef AMBIENTE_H
#define AMBIENTE_H

#include "substancia.h"

class Ambiente {
public:
    float p; // Pressão
    float t; // Temperatura

    Ambiente(float pressao, float temp);
    Ambiente(float temp, float altura, float forca);

    float getP1() const;
    float getP2(float altura) const;

private:
    static const float M; // Massa molar do ar em kg/mol
    static const float g; // Aceleração devido à gravidade em m/s²
    static const float R; // Constante dos gases em J/(mol·K)
};

#endif // AMBIENTE_H
