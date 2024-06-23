#include <iostream>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"
#include "interface.h"

int main() {

    int loops_agua,loops_benzeno,loops_etanol;
    Ambiente amb = Ambiente(25,1);
    Substancia agua= Substancia(100,1,0,4184);
    Substancia benzeno = Substancia(100,0.879,0,1720);
    Substancia etanol = Substancia(100,0.789,0,2.44);

    agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb);
    etanol.calculaPontoDeEbulicao(8.20417, 1642.89, 230.300, amb);
    benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb);

    
    while (!agua.entrouEmEbulicao()) {
        agua.esquentar(1000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_agua++;
    }

    while (!etanol.entrouEmEbulicao()) {
        etanol.esquentar(1000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_etanol++;
    }

    while (!benzeno.entrouEmEbulicao()) {
        benzeno.esquentar(1000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_benzeno++;
    }

    std::cout << "Água demorou " << loops_agua << " loops para entrar em ebulição." << std::endl;
    std::cout << "Etanol demorou " << loops_etanol << " loops para entrar em ebulição." << std::endl;
    std::cout << "Benzeno demorou " << loops_benzeno << " loops para entrar em ebulição." << std::endl;

    return 0;
}
