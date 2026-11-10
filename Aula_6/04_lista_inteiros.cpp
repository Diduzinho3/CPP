#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numeros;
    int opcao, valor;

    do {
        cout << "\n1-Inserir  2-Remover primeiro  3-Remover ultimo\n"
             << "4-Remover valor  5-Exibir  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                numeros.push_back(valor);
                break;
            case 2:
                if (numeros.empty()) cout << "Lista vazia.\n";
                else {
                    cout << "Removido: " << numeros.front() << '\n';
                    numeros.pop_front();
                }
                break;
            case 3:
                if (numeros.empty()) cout << "Lista vazia.\n";
                else {
                    cout << "Removido: " << numeros.back() << '\n';
                    numeros.pop_back();
                }
                break;
            case 4: {
                cout << "Valor a remover: ";
                cin >> valor;
                auto antes = numeros.size();
                numeros.remove(valor);
                cout << "Removidas: " << antes - numeros.size() << '\n';
                break;
            }
            case 5:
                if (numeros.empty()) cout << "Lista vazia.\n";
                else {
                    cout << "Lista: ";
                    for (int n : numeros) cout << n << ' ';
                    cout << '\n';
                }
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
