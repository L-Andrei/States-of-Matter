#ifndef AMBIENTE_H
#define AMBIENTE_H

class Ambiente {
private:
    double p; // Pressão em atm;
    double t; // Temperatura em celsius;

public:
    Ambiente(double pressao, double temp);
    double conversor(); // Converte a pressão de atm para mmHg;
    
    double getPressao() const;
    double getTemperatura() const;

};

#endif // AMBIENTE_H