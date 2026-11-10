#include <iostream>
#include <string>
using namespace std;

class Registro {
    string nome;
public:
    explicit Registro(string n) : nome(n) { cout << "Criado: " << nome << '\n'; }
    ~Registro() { cout << "Destruido: " << nome << '\n'; }
};

int main() {
    Registro primeiro("A");
    {
        Registro segundo("B");
        {
            Registro terceiro("C");
        } // C e destruido aqui.
    } // B e destruido aqui.
    cout << "Saindo do main.\n";
} // A e destruido aqui.
