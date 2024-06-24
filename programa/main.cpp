#include <iostream>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"

int main() {

    int loops_agua,loops_benzeno,loops_etanol;
    loops_agua = loops_benzeno = loops_etanol = 0;

    Ambiente amb = Ambiente(1,0);
    Substancia agua= Substancia(100,1,0,4184);
    Substancia benzeno = Substancia(345.5,0.879,0,1720);
    Substancia etanol = Substancia(277500,0.789,0,2.44);

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

    return 0;
}