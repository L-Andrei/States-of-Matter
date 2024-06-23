#include <iostream>
#include <vector>
#include <unistd.h>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"
#include "interface.h"

void Interface::executar(){ // Executa a interface.
    bool sair = false;
    int opcao;
    while(!sair){

        std::cout << "Digite o númeor da operação que deseja realizar:" << std::endl;
        std::cout << "1-Executar teste | 2-Cadastrar substância | 3-Excluir substância | 4-Sair do programa" << std::endl;
        scanf("%d",&opcao);
        
        if(opcao == 1){
            testar();
        }else if(opcao == 2){
            cadastrar();
        }else if(opcao == 3){
            exluir();
        }else if(opcao == 4){
            sair = true;
        }else{
            std::cout << "Esta opção não existe" << std::endl;
        }    
    }
}

void Interface::cadastrar(){ // Cadastra nova subtância e novo ambiente.
    double v,d,t,calor;
    double p,temp;
    double a,b,c;

    std::cout << "Insira o volume da substância" << std::endl;
    scanf("%lf", &v);
    std::cout << "Insira o densidade da substância" << std::endl;
    scanf("%lf", &d);
    std::cout << "Insira o temperatura da substância" << std::endl;
    scanf("%lf", &t);
    std::cout << "Insira o coêficiente de calor especifico da substância" << std::endl;
    scanf("%lf", &calor);
    std::cout << "Insira a pressão que o ambiente, onde se encontre a substância" << std::endl;
    scanf("%lf", &p);
    std::cout << "Insira a temperatura do ambiente, onde se encontre a substância" << std::endl;
    scanf("%lf", &temp);

    s.emplace_back(v,d,t,c);
    amb.emplace_back(p,temp);

    int size_s = s.size(); // Tamanho da lista de substâncias.
    int size_a = amb.size(); // Tamanho da lista de ambientes.

    std::cout << "Insira os três coêficientes especificos da substancia" << std::endl;
    scanf("Primeiro coeficiênte:%lf \n", &a);
    scanf("Segundo coeficiênte:%lf \n", &b);
    scanf("terceiro coeficiênte:%lf \n", &c);

    s[size_s-1].calculaPontoDeEbulicao(a,b,c,amb[size_a-1]);

    std::cout << "objetos cadastrados com sucesso!" << std::endl;
}

void Interface::testar(){ // Executa os testes de ebulição.
    double calorPorSeg;
    int size_s = s.size(); // Tamanho da lista de substâncias.
    int size_a = amb.size(); // Tamanho da lista de ambientes.
    bool ebulicao = false;

    scanf("Insira quantos joules por segundo deseja esquentar as substâncias:%lf",&calorPorSeg);

    while(!ebulicao){
        int soma = 0;
        for(int i = 0; i < size_s ; i++){ // Loop principal que realiza o aquecimento de substancias que ainda não entraram em ebulição.
            if(!(s[i].entrouEmEbulicao())){
            s[i].esquentar(calorPorSeg);
            std::cout << "A substancia " << i << " esta a " << s[i].getTemp() <<" C°" << std::endl;
            }else{
                std::cout << "A substancia " << i << " esta em ebulição" << std::endl;
                soma++;
            }
        }
        if(soma == size_s){
            ebulicao = true;
        }
        sleep(1);
    }
}

void Interface::excluir(){ //Exclui uma substância e um ambiente das listas.
    int posicao;
    scanf("Insira qua a posição da substância e do ambiente que deseja excluir:%d",&posicao);

}