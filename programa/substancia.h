#ifndef SUBSTANCIA_H
#define SUBSTANCIA_H
#include "pontoDeEbulicao.h"
#include "ambiente.h"

class Substancia {
private:

    double volume; // ml
    double d; // Densidade da substancia.
    double m; // g
    double temp; // temperatura inicial. 
    double calor_esp ; // Calor especifico da substancia, exemplo água possui 4184 J/Kg. C°.
    PontoDeEbulicao p; // classe responsável por calcular o ponto de ebulição.
    double temp_ebulicao; // temperatura de ebulição;

public:

    Substancia(double v, double densidade, double t, double c);
    void esquentar(double calorPorSeg);
    void equilibrioTermico(Ambiente amb);
    void calculaPontoDeEbulicao(double a, double b, double c, double pressao);
    bool entrouEmEbulicao();
    double getTemp();
    void setVolume(double v);
    double getPontoDeEbulicao();

};

#endif // SUBSTANCIA_H