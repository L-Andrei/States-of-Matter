#include <iostream>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"
#include "interface.h"

void converterSegundos(int segundos, int& horas, int& minutos, int& seg) {
    horas = segundos / 3600;
    segundos %= 3600;
    minutos = segundos / 60;
    seg = segundos % 60;
}

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
        agua.esquentar(10000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_agua++;
    }

    while (!etanol.entrouEmEbulicao()) {
        etanol.esquentar(10000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_etanol++;
    }

    while (!benzeno.entrouEmEbulicao()) {
        benzeno.esquentar(10000.0); // Supondo que estamos adicionando 1000 joules por segundo
        loops_benzeno++;
    }

    // Convertendo o número de loops em horas, minutos e segundos
    int horas_agua, minutos_agua, seg_agua;
    int horas_etanol, minutos_etanol, seg_etanol;
    int horas_benzeno, minutos_benzeno, seg_benzeno;

    converterSegundos(loops_agua, horas_agua, minutos_agua, seg_agua);
    converterSegundos(loops_etanol, horas_etanol, minutos_etanol, seg_etanol);
    converterSegundos(loops_benzeno, horas_benzeno, minutos_benzeno, seg_benzeno);

    // Exibindo o tempo em horas, minutos e segundos que cada substância demorou para entrar em ebulição
    std::cout << "Água demorou: " << horas_agua << " horas, " << minutos_agua << " minutos e " << seg_agua << " segundos." << std::endl;
    std::cout << "Etanol demorou: " << horas_etanol << " horas, " << minutos_etanol << " minutos e " << seg_etanol << " segundos." << std::endl;
    std::cout << "Benzeno demorou: " << horas_benzeno << " horas, " << minutos_benzeno << " minutos e " << seg_benzeno << " segundos." << std::endl;

    return 0;
}