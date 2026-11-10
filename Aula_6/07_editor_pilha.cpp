#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> palavras;
    int opcao;
    string palavra;

    do {
        cout << "\n1-Digitar palavra  2-Desfazer ultima palavra\n"
             << "3-Consultar ultima  4-Quantidade  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Palavra (sem espacos): ";
                cin >> palavra;
                palavras.push(palavra);
                break;
            case 2:
                if (palavras.empty()) cout << "Nada para desfazer.\n";
                else {
                    cout << "Desfeito: " << palavras.top() << '\n';
                    palavras.pop();
                }
                break;
            case 3:
                if (palavras.empty()) cout << "Editor vazio.\n";
                else cout << "Ultima palavra: " << palavras.top() << '\n';
                break;
            case 4:
                cout << "Palavras: " << palavras.size() << '\n';
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
