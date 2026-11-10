#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> pessoas;
    int opcao;
    string nome;

    do {
        cout << "\n1-Adicionar pessoa  2-Chamar proxima\n"
             << "3-Quantidade aguardando  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Nome: ";
                getline(cin >> ws, nome);
                pessoas.push(nome);
                cout << "Pessoa adicionada.\n";
                break;
            case 2:
                if (pessoas.empty()) cout << "Nao ha pessoas na fila.\n";
                else {
                    cout << "Chamando: " << pessoas.front() << '\n';
                    pessoas.pop();
                }
                break;
            case 3:
                cout << "Aguardando: " << pessoas.size() << '\n';
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
