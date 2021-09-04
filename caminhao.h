#ifndef CAMINHAO_H
#define CAMINHAO_H
#include <string>
#include "veiculo.h"

using namespace std;

class Caminhao:public Veiculo{
// Definindo métodos private
    string tipo;
    string modelo;
    int eixos;
    float capacidade;
    float carga_max;

    // Definindo métodos public
    public:
    // Construtor
    Caminhao(int, string, float, string, string, int);      
    
    // Metodos set
    void setTipo(string);
    void setModelo(string);
    void setEixos(int);

    // Metodos get
    string getTipo() const;
    string getModelo() const;
    int getEixos() const;
    float getCapacidade() const;
    float getCarga_max() const;

};

#endif