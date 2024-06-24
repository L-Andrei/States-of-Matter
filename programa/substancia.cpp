#include <iostream>
#include <cmath>
#include "substancia.h"
#include "pontoDeEbulicao.h"
#include "ambiente.h"

Substancia::Substancia (double v, double densidade, double t, double c){
    volume = v;
    d = densidade;
    temp = t;
    calor_esp = c;
    m = volume * d;
};

void Substancia::esquentar(double calorPorSeg){ // Esquenta a substância com uma quantidade de energia.
    double deltaTemp = calorPorSeg /(m * calor_esp); // A variavel calorPorSeg esta em joules;
    temp += deltaTemp; // aumenta ou diminui a temperatura.
}

void Substancia::equilibrioTermico(Ambiente amb){
    temp = amb.getTemperatura(); // Equilibra a temperatura da substância com a do ambiente.
}

void Substancia::calculaPontoDeEbulicao(double a, double b, double c, double pressao){
    p = PontoDeEbulicao(a,b,c);
    temp_ebulicao = p.calcular(pressao);
}

bool Substancia::entrouEmEbulicao(){
    if(temp >= temp_ebulicao){  // Verifica se a substância já atingiu a temperatura de ebulição.
        return true;
    }else{
        return false;
    }
}

double Substancia::getTemp(){
    return temp;
}

void Substancia::setVolume(double v){
    volume = v;
    m = d * volume;
}

double Substancia::getPontoDeEbulicao(){
    return temp_ebulicao;
}