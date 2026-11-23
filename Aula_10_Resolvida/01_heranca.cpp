// Aula 10 - Exercicio 1: classe base e classe derivada.
#include <iostream>
#include <string>
using namespace std;

class Veiculo {
public:
    string marca;
};

class Carro : public Veiculo {
public:
    int numeroPortas;
};

int main() {
    Carro carro;
    carro.marca = "Toyota";     // Atributo herdado de Veiculo.
    carro.numeroPortas = 4;      // Atributo declarado em Carro.

    cout << "Marca: " << carro.marca << '\n';
    cout << "Numero de portas: " << carro.numeroPortas << '\n';
    return 0;
}
