#include "concessionaria.h"
#include "caminhao.h"
#include "carro.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Construtor recebendo a senha que será utilizada pelo funcionaria
Concessionaria::Concessionaria(int valor) : senha(valor){
    ifstream arquivo_carros("carros.txt");
    ifstream arquivo_caminhoes("caminhoes.txt");
    int ano, eixo;
    string chassi, tipo, modelo, ano_temp, eixo_temp, preco_temp;
    float preco;
    string linha, dados;

    // Ordem dos parametros: int ano, string chassi, float preco, string tipo, string modelo
    // Lendo o arquivo linha por linha e separando os valores em cada virgula
    while (getline(arquivo_carros, linha)){
        stringstream ss(linha);
        getline(ss, ano_temp, ',');
        ano = stoi(ano_temp);   // String para Int
        getline(ss, chassi, ',');
        getline(ss, preco_temp, ',');
        preco = stof(preco_temp);   // String para Float
        getline(ss, tipo, ',');
        getline(ss, modelo, ',');
        Carro carro(ano, chassi, preco, tipo, modelo);
        carros.push_back(carro);
    }
    // Ordem dos parametros: int ano, string chassi, float preco, string tipo, string modelo, int eixo
    while (getline(arquivo_caminhoes, linha)){
        stringstream ss(linha);
        getline(ss, ano_temp, ',');
        ano = stoi(ano_temp);   // String para Int
        getline(ss, chassi, ',');
        getline(ss, preco_temp, ',');
        preco = stof(preco_temp);   // String para Float
        getline(ss, tipo, ',');
        getline(ss, modelo, ',');
        getline(ss, eixo_temp, ',');
        eixo = stoi(eixo_temp);
        Caminhao caminhao(ano, chassi, preco, tipo, modelo, eixo);
        caminhoes.push_back(caminhao);
    }
}

// Cadastro de carro
void Concessionaria::cadastrarCarro(Carro carro){
    bool verificar_chassi = true;
    for(int i=0; i < carros.size(); i++){
        if(carro.getChassi() == carros[i].getChassi()){
            verificar_chassi = false;
        }
    }
    for(int i=0; i < caminhoes.size(); i++){
        if(carro.getChassi() == caminhoes[i].getChassi()){
            verificar_chassi = false;
        }
    }
    if(verificar_chassi){
        carros.push_back(carro);
        cout << "Carro cadastrado com sucesso" << endl;
    }
    else{
        cout << "Não foi possível cadastrar o carro, pois já existe um veículo com esse chassi." << endl;
    }
}

// Cadastro de caminhao
void Concessionaria::cadastrarCaminhao(Caminhao caminhao){
    bool verificar_chassi = true;
    for(int i=0; i < carros.size(); i++){
        if(caminhao.getChassi() == carros[i].getChassi()){
            verificar_chassi = false;
        }
    }
    for(int i=0; i < caminhoes.size(); i++){
        if(caminhao.getChassi() == caminhoes[i].getChassi()){
            verificar_chassi = false;
        }
    }
    if(verificar_chassi){
        caminhoes.push_back(caminhao);
        cout << "Caminhão cadastrado com sucesso" << endl;
    }
    else{
        cout << "Não foi possível cadastrar o caminhão, pois já existe um veículo com esse chassi." << endl;
    }
}

// Vender carros ou caminhoes
void Concessionaria::venderVeiculo(string chassi){
    bool teste = true;
    // Buscando se o chassi existe entre os carros
    for(int i=0; i<carros.size(); i++){
        if(carros[i].getChassi() == chassi){
            carros.erase(carros.begin()+i);
            cout << "Carro vendido com sucesso, parabéns pela venda!" << endl << endl;
            teste = false;
            break;
        }
    }
    // Caso não tenha sido encontrado um carro
    if(teste){
        bool teste2 = true;
        // Buscando entre os caminhoes
        for(int i=0; i<caminhoes.size(); i++){
            if(caminhoes[i].getChassi() == chassi){
                caminhoes.erase(caminhoes.begin()+i);
                cout << "Caminhão vendido com sucesso, parabéns pela venda!" << endl << endl;
                teste = false;
                break;
            }
        }
        // Caso não encontre nem carro nem caminhao
        if(teste && teste2){
            cout << "Chassi não cadastrado." << endl << endl;
        }
    }
}

// Funcao auxiliar para exibir um vetor de carros
void exibir_vetor_carros(vector <Carro> carros){
    if(carros.size() != 0){
        cout << "Carros:" << endl << endl;
        for(int i=0; i<carros.size(); i++){
            cout << "Tipo: " << carros[i].getTipo()  << endl;
            cout << "Modelo: " << carros[i].getModelo() << endl;
            cout << "Ano: " << carros[i].getAno() << endl;
            cout << "Chassi: " << carros[i].getChassi() << endl; 
            cout << "Preço: R$ " << fixed << setprecision(2) << carros[i].getPreco() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
}

// Funcao auxiliar para exibir um vetor de caminhoes
void exibir_vetor_caminhoes(vector <Caminhao> caminhoes){
    if(caminhoes.size() != 0){
        cout << "Caminhões:" << endl << endl;
        for(int i=0; i<caminhoes.size(); i++){
            cout << "Tipo: " << caminhoes[i].getTipo()  << endl;
            cout << "Modelo: " << caminhoes[i].getModelo() << endl;
            cout << "Ano: " << caminhoes[i].getAno() << endl;
            cout << "Chassi: " << caminhoes[i].getChassi() << endl; 
            cout << "Quantidade de eixos: " << caminhoes[i].getEixos() << endl;
            cout << "Carga máxima: " << caminhoes[i].getCarga_max() << " ton" << endl;
            cout << "Capacidade: " << caminhoes[i].getCapacidade() << " m3" << endl;
            cout << "Preço: R$ " << fixed << setprecision(2) << caminhoes[i].getPreco() << endl << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
}

// Mostrar os veiculos
void Concessionaria::exibirVeiculos(){
    // Verificando se há carros ou caminhoes
    if(carros.size() != 0 || caminhoes.size() != 0){
        cout << "Lista com todos os veículos" << endl;
        cout << "#############################" << endl;
        // Exibir carros
        exibir_vetor_carros(carros);
        if(carros.size() != 0){
            cout << "#############################" << endl;
        }
        // Exibir caminhoes
        exibir_vetor_caminhoes(caminhoes);
    }
    else{
        cout << "Ainda não há nenhum veículo para ser exibido" << endl << endl;
    }
}

// Exibir caminhoes para o cliente
void Concessionaria::exibirCaminhoesCliente(int opcao){
    if(opcao == 1){
        // Criando vetor temporario ordenado pelo preco
        vector <Caminhao> temp;
        for(int i = 0; i<caminhoes.size(); i++){
            // O primeiro elemento do vetor será sempre adicionado 
            if(i == 0){
                temp.push_back(caminhoes[0]);
            }
            else{
                // Comparando o elemento i do vetor original com cada um dos outros elementos que ja estao no vetor temporario
                int n = 0;
                bool adicionou = false;
                while(n<i){
                    adicionou = false;
                    if(caminhoes[i].getPreco() > temp[i-n-1].getPreco()){
                        temp.insert(temp.begin()+i-n, caminhoes[i]);
                        adicionou = true;
                        n = i;
                    }
                    if(!adicionou && (n == i-1)){
                        temp.insert(temp.begin(), caminhoes[i]);
                        n = i;
                    }
                    n++;
                }
            }
        }
        cout << "Caminhões ordenados pelo preço" << endl;
        cout << "-------------------------------------" << endl;
        exibir_vetor_caminhoes(temp);
    }
    else if(opcao == 2){
        // Criando vetor temporario ordenado pelo ano
        vector <Caminhao> temp;
        for(int i = 0; i<caminhoes.size(); i++){
            if(i == 0){
                temp.push_back(caminhoes[0]);
            }
            else{
                // Comparando o elemento i do vetor original com cada um dos outros elementos que ja estao no vetor temporario
                int n = 0;
                bool adicionou = false;
                while(n<i){
                    adicionou = false;
                    if(caminhoes[i].getAno() > temp[i-n-1].getAno()){
                        temp.insert(temp.begin()+i-n, caminhoes[i]);
                        adicionou = true;
                        n = i;
                    }
                    if(!adicionou && (n == i-1)){
                        temp.insert(temp.begin(), caminhoes[i]);
                        n = i;
                    }
                    n++;
                }
            }
        }
        cout << "Caminhões ordenados pelo ano" << endl;
        cout << "-------------------------------------" << endl;
        exibir_vetor_caminhoes(temp);
    }
    else if(opcao == 3){
        // Criando vetor temporario ordenado pelo eixo
        vector <Caminhao> temp;
        for(int i = 0; i<caminhoes.size(); i++){
            if(i == 0){
                temp.push_back(caminhoes[0]);
            }
            else{
                int n = 0;
                bool adicionou = false;
                while(n<i){
                    adicionou = false;
                    if(caminhoes[i].getEixos() > temp[i-n-1].getEixos()){
                        temp.insert(temp.begin()+i-n, caminhoes[i]);
                        adicionou = true;
                        n = i;
                    }
                    if(!adicionou && (n == i-1)){
                        temp.insert(temp.begin(), caminhoes[i]);
                        n = i;
                    }
                    n++;
                }
            }
        }
        cout << "Caminhões ordenados pelos eixos" << endl;
        cout << "-------------------------------------" << endl;
        exibir_vetor_caminhoes(temp);
    }
    else{
        cout << "Opção inválida!" << endl;
        cout << "########################" << endl << endl;
    }
}
// Exibir carros para o cliente
void Concessionaria::exibirCarrosCliente(int opcao){
    if(opcao == 1){
        // Criando vetor temporario ordenado pelo preco
        vector <Carro> temp;
        for(int i = 0; i<carros.size(); i++){
            if(i == 0){
                temp.push_back(carros[0]);
            }
            else{
                int n = 0;
                bool adicionou = false;
                while(n<i){
                    adicionou = false;
                    if(carros[i].getPreco() > temp[i-n-1].getPreco()){
                        temp.insert(temp.begin()+i-n, carros[i]);
                        adicionou = true;
                        n = i;
                    }
                    if(!adicionou && (n == i-1)){
                        temp.insert(temp.begin(), carros[i]);
                        n = i;
                    }
                    n++;
                }
            }
        }
        cout << "Carros ordenados pelo preço" << endl;
        cout << "-------------------------------------" << endl;
        exibir_vetor_carros(temp);
    }
    else if(opcao == 2){
        // Criando vetor temporario ordenado pelo ano
        vector <Carro> temp;
        for(int i = 0; i<carros.size(); i++){
            if(i == 0){
                temp.push_back(carros[0]);
            }
            else{
                int n = 0;
                bool adicionou = false;
                while(n<i){
                    adicionou = false;
                    if(carros[i].getAno() > temp[i-n-1].getAno()){
                        temp.insert(temp.begin()+i-n, carros[i]);
                        adicionou = true;
                        n = i;
                    }
                    if(!adicionou && (n == i-1)){
                        temp.insert(temp.begin(), carros[i]);
                        n = i;
                    }
                    n++;
                }
            }
        }
        cout << "Carros ordenados pelo preço" << endl;
        cout << "-------------------------------------" << endl;
        exibir_vetor_carros(temp);
    }
    else{
        cout << "Opção inválida!" << endl;
        cout << "########################" << endl << endl;
    }
}

// Menu
void Concessionaria::menu(){
    int usuario = 0;
    int stop = 0;
    cout << "Bem-vindo a concessionária" << endl;
    cout << "###########################" << endl;
    while(stop != 3){
        cout << "Como você deseja acessar o sistema?" << endl;
        cout << "1 - Funcionário" << endl;
        cout << "2 - Cliente" << endl;
        cout << "3 - Encerrar programa" << endl;
        cin >> usuario;
        if(usuario == 1){
            int teste_senha;
            cout << "Usuário: Funcionário" << endl;
            cout << "-------------------------" << endl;
            cout << "Digite a senha: ";
            cin >> teste_senha;
            if(teste_senha == senha){
                int stop2 = 0;
                cout << "Acesso liberado!" << endl << endl;
                cout << "O que você deseja fazer?" << endl;
                while(stop2 == 0){
                    int opcao = 0;
                    cout << "1 - Cadastrar um veículo" << endl;
                    cout << "2 - Vender um veículo" << endl;
                    cout << "3 - Exibir veículos cadastrados" << endl;
                    cout << "4 - Sair do menu funcionário" << endl;
                    cin >> opcao;
                    if(opcao == 1){
                        int alternativa = 0;
                        cout << "---------------------------" << endl;
                        cout << "Cadastro de veículo" << endl << endl;

                        cout << "Qual é o tipo do veículo?" << endl;
                        cout << "1 - Carro" << endl;
                        cout << "2 - Caminhão" << endl;
                        cin >> alternativa;
                        if(alternativa == 1){
                            cout << "Cadastrando carro..." << endl;
                            cout << "-----------------------" << endl;
                            int ano;
                            string chassi, tipo, modelo;
                            float preco;
                            cout << "Digite o tipo (Sedan, SUV, Picape, Crossover, Hatch...): ";
                            getline(cin.ignore(), tipo);
                            cout << "Digite o modelo do carro (Duster, Renegade, Gol, Uno...): ";
                            getline(cin, modelo);
                            cout << "Digite o ano do veículo: ";
                            cin >> ano;
                            cout << "Digite o chassi: ";
                            getline(cin.ignore(), chassi);
                            cout << "Digite o preço de venda: ";
                            cin >> preco;
                            Carro carro(ano, chassi, preco, tipo, modelo);
                            cadastrarCarro(carro);
                            cout << "-------------------------------" << endl;
                        }
                        else if(alternativa == 2){
                            cout << "Cadastrando caminhão..." << endl;
                            cout << "-----------------------" << endl;
                            int ano, eixos;
                            string chassi, tipo, modelo;
                            float preco;
                            cout << "Digite o tipo (Toco, Truck, Carreta simples ou Carreta Eixo Estendid): ";
                            getline(cin.ignore(), tipo);
                            cout << "Digite o modelo do caminhão (Vw 15190, Ford F11000...): ";
                            getline(cin, modelo);
                            cout << "Digite o ano do veículo: ";
                            cin >> ano;
                            cout << "Digite o número de eixos (2, 3, 5 ou 6): ";
                            cin >> eixos;
                            cout << "Digite o chassi: ";
                            getline(cin.ignore(), chassi);
                            cout << "Digite o preço de venda: ";
                            cin >> preco;
                            Caminhao caminhao(ano, chassi, preco, tipo, modelo, eixos);
                            cadastrarCaminhao(caminhao);
                            cout << "-------------------------------" << endl;
                        }
                        else{
                            cout << "Opção inválida, tente novamente" << endl << endl;
                        }
                    }
                    else if(opcao == 2){
                        cout << "----------------------" << endl;
                        cout << "Venda um veículo..." << endl << endl;

                        string chassi;
                        cout << "Digite o chassi do veículo que você deseja vender: ";
                        cin >> chassi;
                        venderVeiculo(chassi);
                        cout << "-----------------------------------------------------" << endl;
                    }
                    else if(opcao == 3){
                        exibirVeiculos();
                    }
                    else if(opcao == 4){
                        cout << "Saindo do menu funcionário..." << endl;
                        cout << "###########################" << endl;
                        // Alterando o stop2 para encerrar o loop while
                        stop2 = 1;
                        // Alterando valor do teste para que ele fique diferente da senha
                        // Assim, o menu encerrará
                        teste_senha++;
                    }
                    else{
                        cout << "Opção inválida, tente novamente" << endl << endl;
                    }
                }
            }
            else{
                cout << "Senha incorreta!" << endl;
                cout << "###########################" << endl;
                usuario = 0;
            }
        }
        else if(usuario == 2){
            bool encerrar_cliente = false;
            while(!encerrar_cliente){
                cout << "###########################" << endl;
                cout << "Menu do cliente" << endl;
                cout << "Seja bem-vindo!" << endl << endl;

                bool continuar = true;
                while(continuar){
                    cout << "Qual tipo de veículo você deseja visualizar?" << endl;
                    int escolha;
                    cout << "1 - Carro" << endl;
                    cout << "2 - Caminhão" << endl;
                    cout << "3 - Encerrar cliente" << endl;
                    cin >> escolha;
                    if(escolha == 1){
                        int vizualizacao;
                        cout << "Como você deseja vizualizar os carros?" << endl;
                        cout << "------------------------------------------------" << endl;
                        cout << "1 - Ordenados pelo preço" << endl;
                        cout << "2 - Ordenados pelo ano" << endl;
                        cin >> vizualizacao;
                        exibirCarrosCliente(vizualizacao);
                    }
                    else if(escolha == 2){
                        int vizualizacao;
                        cout << "Como você deseja vizualizar os caminhões?" << endl;
                        cout << "------------------------------------------------" << endl;
                        cout << "1 - Ordenados pelo preço" << endl;
                        cout << "2 - Ordenados pelo ano" << endl;
                        cout << "3 - Ordenar pelo número de eixos" << endl;
                        cin >> vizualizacao;
                        exibirCaminhoesCliente(vizualizacao);
                    }
                    else if(escolha == 3){
                        cout << "Saindo do menu cliente..." << endl;
                        cout << "###########################" << endl;
                        continuar = false;
                        encerrar_cliente = true;
                    }
                    else{
                        cout << "Opção inválida!" << endl << endl;
                    }
                    }
                }
            }
            else if(usuario == 3){
                stop = 3;
                cout << "Encerrrando programa..." << endl;
                cout << "Até a próxima!" << endl;
                usuario = 0;
            }
            else{
                cout << "Opção inválida, tente novamente" << endl << endl;
            }
            
    }
}

// Destrutor para salvar os dados no arquivos .txt
Concessionaria::~Concessionaria(){
    fstream arquivo;
    arquivo.open("carros.txt", ios::out); // Abrir arquivo
    for(int i = 0; i < carros.size(); i++){
        if(arquivo.is_open()){
            arquivo << carros[i].getAno() << ",";
            arquivo << carros[i].getChassi() << ",";
            arquivo << carros[i].getPreco() << ",";
            arquivo << carros[i].getTipo() << ",";
            arquivo << carros[i].getModelo() << endl;
        }
    }
    arquivo.close();
    fstream arquivo2;
        arquivo2.open("caminhoes.txt", ios::out); 
        for(int i = 0; i < caminhoes.size(); i++){
        if(arquivo2.is_open()){
            arquivo2 << caminhoes[i].getAno() << ",";
            arquivo2 << caminhoes[i].getChassi() << ",";
            arquivo2 << caminhoes[i].getPreco() << ",";
            arquivo2 << caminhoes[i].getTipo() << ",";
            arquivo2 << caminhoes[i].getModelo() << ",";
            arquivo2 << caminhoes[i].getEixos() << endl;
        }
    }
    arquivo2.close();
}