#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Produto {
    const int codigo;
    string nome;
    double preco;
public:
    Produto(int c, string n, double p) : codigo(c), nome(n), preco(p) {
        if (preco <= 0) throw invalid_argument("Preco invalido");
    }
    void mostrar() const {
        cout << "Codigo: " << codigo << " | Nome: " << nome << " | Preco: " << preco << '\n';
    }
};

int main() {
    Produto p(101, "Teclado", 89.9);
    p.mostrar();
    // const int codigo precisa ser inicializado ANTES do corpo do construtor.
    // Fazer codigo = 101; no corpo seria erro de compilacao.
}
