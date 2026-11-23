// Aula 10 - Exercicio 4: compare compilando com e sem -DSEM_VIRTUAL.
#include <iostream>
#include <vector>
using namespace std;

class Veiculo {
public:
#ifndef SEM_VIRTUAL
    virtual void emitirSom() const {
#else
    void emitirSom() const {
#endif
        cout << "Veiculo: ruido generico do motor.\n";
    }
    virtual ~Veiculo() = default;
};

class Carro : public Veiculo {
public:
#ifndef SEM_VIRTUAL
    void emitirSom() const override {
#else
    void emitirSom() const {
#endif
        cout << "Carro: bi-bi!\n";
    }
};

class Motocicleta : public Veiculo {
public:
#ifndef SEM_VIRTUAL
    void emitirSom() const override {
#else
    void emitirSom() const {
#endif
        cout << "Motocicleta: vruuum!\n";
    }
};

int main() {
    Veiculo veiculo;
    Carro carro;
    Motocicleta moto;
    vector<Veiculo*> frota = {&veiculo, &carro, &moto};

#ifdef SEM_VIRTUAL
    cout << "SEM virtual: vinculacao ESTATICA\n";
#else
    cout << "COM virtual: vinculacao DINAMICA\n";
#endif
    for (Veiculo* item : frota) {
        item->emitirSom();  // Mesmo codigo, resultados diferentes.
    }
    return 0;
}
