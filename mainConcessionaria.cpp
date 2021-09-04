/*
Christian Ubiratan

> Feito no VS Code

>Descrição do programa: Simulação de uma concessionária de veículos com implementacao do cliente e fucionario*/

#include "concessionaria.cpp"
#include "veiculo.cpp"
#include "carro.cpp"
#include "caminhao.cpp"

// Funçao principal
int main(){
    // Inicializando uma concessionária
    // O parâmetro do objeto é a senha do funcionário
    Concessionaria C1(12345);
    C1.menu();
    return 0;
}
