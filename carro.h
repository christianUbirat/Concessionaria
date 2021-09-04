#ifndef CARRO_H
#define CARRO_H
#include <string>
#include "veiculo.h"

using namespace std;

class Carro:public Veiculo{
// Definindo métodos private
    string tipo;
    string modelo;

    // Definindo métodos public
    public:
    // Construtor
    Carro(int, string, float, string, string);      
    
    // Metodos set
    void setTipo(string);
    void setModelo(string);

    // Metodos get
    string getTipo() const;
    string getModelo() const;
};

#endif