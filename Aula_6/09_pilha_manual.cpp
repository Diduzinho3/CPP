#include <iostream>
using namespace std;

const int CAPACIDADE = 5;

struct Pilha {
    int dados[CAPACIDADE];
    int topo = -1; // -1 significa pilha vazia.

    bool vazia() const { return topo == -1; }
    bool cheia() const { return topo == CAPACIDADE - 1; }
    bool empilhar(int valor) {
        if (cheia()) return false;
        dados[++topo] = valor;
        return true;
    }
    bool desempilhar(int& valor) {
        if (vazia()) return false;
        valor = dados[topo--];
        return true;
    }
    bool consultarTopo(int& valor) const {
        if (vazia()) return false;
        valor = dados[topo];
        return true;
    }
};

int main() {
    Pilha p;
    int opcao, valor;
    do {
        cout << "\n1-Empilhar  2-Desempilhar  3-Consultar topo\n"
             << "4-Verificar vazia  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                cout << (p.empilhar(valor) ? "Empilhado.\n" : "Pilha cheia.\n");
                break;
            case 2:
                if (p.desempilhar(valor)) cout << "Desempilhado: " << valor << '\n';
                else cout << "Pilha vazia.\n";
                break;
            case 3:
                if (p.consultarTopo(valor)) cout << "Topo: " << valor << '\n';
                else cout << "Pilha vazia.\n";
                break;
            case 4:
                cout << (p.vazia() ? "Pilha vazia.\n" : "Pilha nao vazia.\n");
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
