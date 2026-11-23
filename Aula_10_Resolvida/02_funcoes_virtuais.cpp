// Aula 10 - Exercicio 2: virtual e override.
#include <iostream>
#include <string>
using namespace std;

class Veiculo {
public:
    string marca;

    virtual void emitirSom() const {
        cout << "Veiculo: ruido generico do motor.\n";
    }

    virtual ~Veiculo() = default;
};

class Carro : public Veiculo {
public:
    void emitirSom() const override {
        cout << "Carro: bi-bi! (buzina)\n";
    }
};

class Motocicleta : public Veiculo {
public:
    void emitirSom() const override {
        cout << "Motocicleta: vruuum!\n";
    }
};

int main() {
    Veiculo veiculo;
    Carro carro;
    Motocicleta moto;

    cout << "Testando as tres implementacoes:\n";
    veiculo.emitirSom();
    carro.emitirSom();
    moto.emitirSom();

    // Por ser virtual, a chamada tambem funciona atraves da classe base.
    Veiculo* referenciaAoCarro = &carro;
    cout << "Por ponteiro Veiculo: ";
    referenciaAoCarro->emitirSom();
    return 0;
}
