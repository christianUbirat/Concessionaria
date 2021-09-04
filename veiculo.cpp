#include "veiculo.h"

// Construtor
Veiculo::Veiculo(int ano, string chassi, float preco){
    this->ano = ano;
    this->chassi = chassi;
    this->preco = preco;
}

// Metodos set
void Veiculo::setAno(int ano){
    this->ano = ano;
}
void Veiculo::setChassi(string chassi){
    this->chassi = chassi;
}
void Veiculo::setPreco(float preco){
    this->preco = preco;
}

// Metodos get
int Veiculo::getAno() const{
    return ano;
}
string Veiculo::getChassi() const{
    return chassi;
}
float Veiculo::getPreco() const{
    return preco;
}
