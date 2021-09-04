#ifndef VEICULO_H
#define VEICULO_H
#include <string>

using namespace std;

class Veiculo{
// Definindo métodos private
    int ano;
    string chassi;
    float preco;

    // Definindo métodos public
    public:
    // Construtor
    Veiculo(int ano = 0, string chassi = "", float preco = 0);      
    
    // Metodos set
    void setAno(int);
    void setChassi(string);
    void setPreco(float);

    // Metodos get
    int getAno() const;
    string getChassi() const;
    float getPreco() const;

};

#endif