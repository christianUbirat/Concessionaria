#include "caminhao.h"
#include <fstream>

// Construtor
Caminhao::Caminhao(int ano, string chassi, float preco, string tipo, string modelo, int eixo){
    // Criacao do objeto
    setAno(ano);
    setChassi(chassi);
    setPreco(preco);
    setTipo(tipo);
    setModelo(modelo);
    setEixos(eixo);
    if(eixo == 2){
        carga_max = 5;
        capacidade = 44;
    }
    else if(eixo == 3){
        carga_max = 11;
        capacidade = 58;
    }
    else if(eixo == 5){
        carga_max = 25;
        capacidade = 97;
    }
    else if(eixo == 6){
        carga_max = 33;
        capacidade = 97;    
    }

}

// Metodos set
void Caminhao::setTipo(string tipo){
    this->tipo = tipo;
}
void Caminhao::setModelo(string modelo){
    this->modelo = modelo;
}
void Caminhao::setEixos(int eixos){
    this->eixos = eixos;
}

// Metodos get
string Caminhao::getTipo() const{
    return tipo;
}
string Caminhao::getModelo() const{
    return modelo;
}
int Caminhao::getEixos() const{
    return eixos;
}
float Caminhao::getCapacidade() const{
    return capacidade;
}
float Caminhao::getCarga_max() const{
    return carga_max;
}
  
// Destrutor
/*
Caminhao::~Caminhao(){
    fstream arquivo;
    arquivo.open("caminhoes.txt", ios::app); // Escrever no arquivo
    if(arquivo.is_open()){
        arquivo << getAno() << ", ";
        arquivo << getChassi() << ", ";
        arquivo << getPreco() << ", ";
        arquivo << getTipo() << ", ";
        arquivo << getModelo() << ", ";
        arquivo << getEixos() << endl;
    }
    arquivo.close();
}
*/