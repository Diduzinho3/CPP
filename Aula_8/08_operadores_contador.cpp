#include <iostream>
#include <stdexcept>
using namespace std;

class Contador {
    int valor;
public:
    explicit Contador(int v = 1) : valor(v) {
        if (v <= 0) throw invalid_argument("Contador deve ser positivo");
    }
    int get() const { return valor; }
    Contador& operator++() { ++valor; return *this; } // Prefixado: atualizado.
    Contador operator++(int) { // Posfixado: copia anterior (int ficticio).
        Contador antigo(*this);
        ++valor;
        return antigo;
    }
};

int main() {
    Contador c(3);
    cout << "Inicial: " << c.get() << '\n';
    cout << "++c retornou: " << (++c).get() << ", atual: " << c.get() << '\n';
    cout << "c++ retornou: " << (c++).get() << ", atual: " << c.get() << '\n';
}
