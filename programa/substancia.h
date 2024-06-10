#ifndef SUBSTANCIA_H
#define SUBSTANCIA_H

class Substancia {
public:
    double volume;
    double m_mols;
    double m;
    double mols;
    double entalpia;
    double calor_latente_vaporizacao;
    double calor_latente_fusao;

    Substancia (double v, double g_mols, double massa, double calor_latente_vaporizacao, double calor_latente_fusao);

    void calcula_entalpia_vaporizacao();
    void calcula_entalpia_fusao();
    double calculaPontoEbulicao();

    // Getters and setters
    double getCalorLatenteVaporizacao() const;
    void setCalorLatenteVaporizacao(double clv);
    double getCalorLatenteFusao() const;
    void setCalorLatenteFusao(double clf);
};

#endif // SUBSTANCIA_H