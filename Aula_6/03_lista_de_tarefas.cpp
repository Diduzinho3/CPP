#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<string> tarefas;
    int opcao;
    string tarefa;

    do {
        cout << "\n1-Inserir no inicio  2-Inserir no fim  3-Remover por texto\n"
             << "4-Listar  5-Quantidade  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;

        switch (opcao) {
            case 1:
            case 2:
                cout << "Tarefa: ";
                getline(cin >> ws, tarefa);
                if (opcao == 1) tarefas.push_front(tarefa);
                else tarefas.push_back(tarefa);
                cout << "Tarefa adicionada.\n";
                break;
            case 3: {
                cout << "Texto exato da tarefa: ";
                getline(cin >> ws, tarefa);
                auto antes = tarefas.size();
                tarefas.remove(tarefa); // Remove todas as ocorrencias iguais.
                cout << "Removidas: " << antes - tarefas.size() << '\n';
                break;
            }
            case 4:
                if (tarefas.empty()) cout << "Lista vazia.\n";
                else for (const string& item : tarefas) cout << "- " << item << '\n';
                break;
            case 5:
                cout << "Quantidade: " << tarefas.size() << '\n';
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
