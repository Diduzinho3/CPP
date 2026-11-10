#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    int codigo;
    string descricao;
    double preco;

public:
    Produto(int codigo, string descricao, double preco)
        : codigo(codigo), descricao(descricao), preco(1.0) {
        setPreco(preco);
    }

    int getCodigo() const { return codigo; }
    string getDescricao() const { return descricao; }
    double getPreco() const { return preco; }

    bool setPreco(double novoPreco) {
        if (novoPreco <= 0) return false;
        preco = novoPreco;
        return true;
    }
};

int main() {
    Produto p(101, "Teclado", 120.0);
    // p.preco = -10; // ERRO de compilacao: preco e privado.
    cout << "Codigo: " << p.getCodigo()
         << " | Descricao: " << p.getDescricao()
         << " | Preco: R$ " << p.getPreco() << '\n';
    if (!p.setPreco(-10)) cout << "Preco rejeitado: deve ser positivo.\n";
    p.setPreco(99.90);
    cout << "Preco atualizado: R$ " << p.getPreco() << '\n';
    return 0;
}
