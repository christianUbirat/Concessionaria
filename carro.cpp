#include "carro.h"
#include <fstream>

// Construtor
Carro::Carro(int ano, string chassi, float preco, string tipo, string modelo){
    setAno(ano);
    setChassi(chassi);
    setPreco(preco);
    setTipo(tipo);
    setModelo(modelo);
}

// Metodos set
void Carro::setTipo(string tipo){
    this->tipo = tipo;
}
void Carro::setModelo(string modelo){
    this->modelo = modelo;
}

// Metodos get
string Carro::getTipo() const{
    return tipo;
}
string Carro::getModelo() const{
    return modelo;
}

// Destrutor
/*
Carro::~Carro(){
    fstream arquivo;
    arquivo.open("carros.txt", ios::app); // Abrir arquivo
    if(arquivo.is_open()){
        arquivo << getAno() << ", ";
        arquivo << getChassi() << ", ";
        arquivo << getPreco() << ", ";
        arquivo << getTipo() << ", ";
        arquivo << getModelo() << endl;
    }
    arquivo.close();
}
*/