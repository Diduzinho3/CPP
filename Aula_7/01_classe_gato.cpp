#include <iostream>
#include <string>
using namespace std;

class Gato {
private:
    string nome;
    int idade;
    double peso;

public:
    Gato(string nome, int idade, double peso)
        : nome(nome), idade(idade), peso(1.0) {
        setPeso(peso);
    }

    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    double getPeso() const { return peso; }

    bool setPeso(double novoPeso) {
        if (novoPeso <= 0) return false;
        peso = novoPeso;
        return true;
    }
};

int main() {
    Gato gato("Mingau", 3, 4.5);
    cout << "Nome: " << gato.getNome()
         << " | Idade: " << gato.getIdade()
         << " | Peso: " << gato.getPeso() << " kg\n";

    if (!gato.setPeso(-2.0)) cout << "Peso invalido!\n";
    cout << "Peso depois da tentativa: " << gato.getPeso() << " kg\n";
    gato.setPeso(5.1);
    cout << "Novo peso: " << gato.getPeso() << " kg\n";
    return 0;
}
