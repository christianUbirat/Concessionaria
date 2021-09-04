#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <vector>
#include "caminhao.h"
#include "carro.h"

using namespace std;

class Concessionaria{
// Definindo métodos private
    const int senha;
    vector <Caminhao> caminhoes;
    vector <Carro> carros;
  
    // Definindo métodos public
    public:
    // Construtor
    Concessionaria(int);      
    
    // Metodos set
    
    // Metodos uteis
    void menu();
    void cadastrarCarro(Carro);
    void cadastrarCaminhao(Caminhao);
    void venderVeiculo(string);
    void exibirVeiculos();
    void exibirCarrosCliente(int);
    void exibirCaminhoesCliente(int);

    // Destrutor
    ~Concessionaria();
};

#endif