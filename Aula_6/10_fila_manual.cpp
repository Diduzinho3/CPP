#include <iostream>
using namespace std;

const int CAPACIDADE = 5;

struct Fila {
    int dados[CAPACIDADE];
    int inicio = 0;
    int fim = 0;
    int quantidade = 0;

    bool vazia() const { return quantidade == 0; }
    bool cheia() const { return quantidade == CAPACIDADE; }
    bool inserir(int valor) {
        if (cheia()) return false;
        dados[fim] = valor;
        fim = (fim + 1) % CAPACIDADE; // Array circular.
        ++quantidade;
        return true;
    }
    bool remover(int& valor) {
        if (vazia()) return false;
        valor = dados[inicio];
        inicio = (inicio + 1) % CAPACIDADE;
        --quantidade;
        return true;
    }
};

int main() {
    Fila fila;
    int opcao, valor;
    do {
        cout << "\n1-Inserir  2-Remover  3-Verificar vazia"
             << "  4-Quantidade  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                cout << (fila.inserir(valor) ? "Inserido.\n" : "Fila cheia.\n");
                break;
            case 2:
                if (fila.remover(valor)) cout << "Removido: " << valor << '\n';
                else cout << "Fila vazia.\n";
                break;
            case 3:
                cout << (fila.vazia() ? "Fila vazia.\n" : "Fila nao vazia.\n");
                break;
            case 4:
                cout << "Quantidade: " << fila.quantidade << '\n';
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
