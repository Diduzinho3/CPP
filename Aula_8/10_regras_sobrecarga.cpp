#include <iostream>
#include <string>
using namespace std;

class Numero {
    int valor;
public:
    explicit Numero(int valor) : valor(valor) {}
    Numero operator+(const Numero& outro) const { return Numero(valor + outro.valor); }
    int get() const { return valor; }
};

int main() {
    Numero a(3), b(4);
    cout << "Sobrecarga permitida Numero + Numero: " << (a + b).get() << '\n';
    cout << "(a) Criar operador inexistente: proibido.\n";
    cout << "(b) Alterar precedencia de +: proibido.\n";
    cout << "(c) Somar objetos da propria classe: permitido.\n";
    cout << "(d) Redefinir int + int: proibido; ao menos um operando deve ser tipo de classe ou enum.\n";
    cout << "(e) Usar + para excluir registros: pode compilar se houver tipo de usuario,\n"
            "mas viola o principio da menor surpresa: + sugere combinacao, nao exclusao.\n";
}
