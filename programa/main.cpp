#include <iostream>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"


void executaTeste(double volume1, double volume2, double volume3){
    int loops_agua,loops_benzeno,loops_etanol; // Variáveis auxiliares.
    loops_agua = loops_benzeno = loops_etanol = 0; 

    //Inicia as substâncias e o ambiente.
    Ambiente amb = Ambiente(1,0); 
    Substancia agua= Substancia(volume1,1,0,4184);
    Substancia benzeno = Substancia(volume2,0.879,0,1720);
    Substancia etanol = Substancia(volume3,0.789,0,2.44);

    // Calcula os pontos de ebulição de cada substância.
    agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb.conversor());
    etanol.calculaPontoDeEbulicao(8.20417, 1642.89, 230.300, amb.conversor());
    benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb.conversor());


    while (!agua.entrouEmEbulicao()) {
        agua.esquentar(50000); 
        loops_agua++;
    }

    while (!etanol.entrouEmEbulicao()) {
        etanol.esquentar(50000); 
        loops_etanol++;
    }

    while (!benzeno.entrouEmEbulicao()) {
        benzeno.esquentar(50000); 
        loops_benzeno++;
    }

    std::cout << "Água demorou: " << loops_agua << std::endl;
    std::cout << "Etanol demorou: " << loops_etanol << std::endl;
    std::cout << "Benzeno demorou: " << loops_benzeno << std::endl;

}


int main() {
    double volume1, volume2, volume3;
    volume1 = 100;
    volume2 = 345.5;
    volume3 = 277500;
    executaTeste(volume1,volume2,volume3);
    return 0;
}