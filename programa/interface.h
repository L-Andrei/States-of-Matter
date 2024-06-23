#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "substancia.h"
#include "ambiente.h"
#include "pontoDeEbulicao.h"

class Interface{

    private:
        std::vector<Substancia> s;
        std::vector<Ambiente> amb;

    public:
        void executar();
        void testar();
        void cadastrar();
        void excluir();
        
};
#endif 