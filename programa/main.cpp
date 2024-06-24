#include <iostream>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"


void executaTeste(double volume1, double volume2, double volume3, double aquecimento){
    int loops_agua,loops_benzeno,loops_etanol; // Variáveis auxiliares.
    loops_agua = loops_benzeno = loops_etanol = 0; 

    //Inicia as substâncias e o ambiente.
    Ambiente amb = Ambiente(1,0); // ambiente a nível do mar.
    Substancia agua= Substancia(volume1,1,0,4184);
    Substancia benzeno = Substancia(volume2,0.879,0,1720);
    Substancia etanol = Substancia(volume3,0.789,0,2.44);

    // Calcula os pontos de ebulição de cada substância.
    agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb.conversor());
    etanol.calculaPontoDeEbulicao(8.20417, 1642.89, 230.300, amb.conversor());
    benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb.conversor());


    while (!agua.entrouEmEbulicao()) {
        agua.esquentar(aquecimento); 
        loops_agua++;
    }

    while (!etanol.entrouEmEbulicao()) {
        etanol.esquentar(aquecimento); 
        loops_etanol++;
    }

    while (!benzeno.entrouEmEbulicao()) {
        benzeno.esquentar(aquecimento); 
        loops_benzeno++;
    }

    std::cout << "Água demorou: " << loops_agua << " segundos" << std::endl;
    std::cout << "Etanol demorou: " << loops_etanol << " segundos" << std::endl;
    std::cout << "Benzeno demorou: " << loops_benzeno << " segundos" << std::endl;
    std::cout << "\n" << std::endl;
}

void compara(double v1, double v2, double aquecimento){
    bool sair = true;
    Ambiente amb = Ambiente(1,0); // ambiente a nível do mar.
    Substancia agua= Substancia(v1,1,0,4184);
    Substancia benzeno = Substancia(v2,0.879,0,1720);

    // Calcula os pontos de ebulição de cada substância.
    agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb.conversor());
    benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb.conversor());

    while(sair){

        agua.esquentar(aquecimento);
        benzeno.esquentar(aquecimento);

        if(agua.entrouEmEbulicao() && benzeno.entrouEmEbulicao()){

            sair = false;

        }else if(agua.entrouEmEbulicao()){

            agua = Substancia(v1+=1,1,0,4184);
            benzeno = Substancia(v2,0.879,0,1720);
            agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb.conversor());
            benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb.conversor());

        }else if(benzeno.entrouEmEbulicao()){

            agua = Substancia(v1,1,0,4184);
            benzeno = Substancia(v2+=1,0.879,0,1720);
            agua.calculaPontoDeEbulicao(8.07131, 1730.63, 233.426, amb.conversor());
            benzeno.calculaPontoDeEbulicao(6.90565, 1211.033, 220.790, amb.conversor());


        }

    }

    std::cout << "Para que o benzeno é a água possuam o mesmo tempo de ebolição a volume de cada um deverá ser:" << std::endl;
    std::cout << "Benzeno " << v2 << " ml" << std::endl;
    std::cout << "Água " << v1 << " ml" << std::endl;
    std::cout << "\n" << std::endl;
}


int main() {
    double volume1, volume2, volume3, aquecimento;

    aquecimento = 50000;
    volume1 = 100;
    volume2 = 345.5;
    volume3 = 277500;
    
    //executaTeste(volume1,volume2,volume3,aquecimento);
    /*
    for(int i=1000; i<100000;i+=10000){
        executaTeste(volume1,volume2,volume3,i);
    }
    */
    compara(100,100,10000);
    executaTeste(121,418,1,10000);
    return 0;
}