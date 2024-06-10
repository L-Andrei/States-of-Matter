#include <iostream>
#include <cmath>
#include "substancia.h"

Substancia::Substancia(double v, double g_mols, double massa, double calor_latente_vaporizacao, double calor_latente_fusao) {
    volume = v;
    m_mols = g_mols;
    m = massa;
    mols = m / g_mols;
    Substancia::calor_latente_vaporizacao = calor_latente_vaporizacao;
    Substancia::calor_latente_fusao = calor_latente_fusao;
    calcula_entalpia_vaporizacao();
}

void Substancia::calcula_entalpia_vaporizacao() {
    entalpia = m * calor_latente_vaporizacao; // m em gramas, calor_latente_vaporizacao em J/g
}

void Substancia::calcula_entalpia_fusao() {
    entalpia = m * calor_latente_fusao; // m em gramas, calor_latente_fusao em J/g
}

double Substancia::getCalorLatenteVaporizacao() const {
    return calor_latente_vaporizacao;
}

void Substancia::setCalorLatenteVaporizacao(double clv) {
    calor_latente_vaporizacao = clv;
    calcula_entalpia_vaporizacao(); // Recalculate entalpia if calor latente changes
}

double Substancia::getCalorLatenteFusao() const {
    return calor_latente_fusao;
}

void Substancia::setCalorLatenteFusao(double clf) {
    calor_latente_fusao = clf;
    calcula_entalpia_fusao(); // Recalculate entalpia if calor latente changes
}

double Substancia::calculaPontoEbulicao() {
    const double R = 8.314; 
    double temperatura_inicial = 273.15; 

    double temperatura_ebulicao = ((calor_latente_vaporizacao * temperatura_inicial ) / R);
    return temperatura_ebulicao;
}
