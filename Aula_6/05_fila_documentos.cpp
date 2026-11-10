#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> documentos;
    int opcao;
    string nome;

    do {
        cout << "\n1-Adicionar documento  2-Imprimir proximo\n"
             << "3-Consultar proximo  4-Verificar fila vazia  0-Sair\nOpcao: ";
        if (!(cin >> opcao)) return 0;
        switch (opcao) {
            case 1:
                cout << "Nome do documento: ";
                getline(cin >> ws, nome);
                documentos.push(nome); // Entra no final.
                break;
            case 2:
                if (documentos.empty()) cout << "Nenhum documento pendente.\n";
                else {
                    cout << "Imprimindo: " << documentos.front() << '\n';
                    documentos.pop(); // Sai o mais antigo.
                }
                break;
            case 3:
                if (documentos.empty()) cout << "Fila vazia.\n";
                else cout << "Proximo: " << documentos.front() << '\n';
                break;
            case 4:
                cout << (documentos.empty() ? "Fila vazia.\n" : "Ha documentos na fila.\n");
                break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
    return 0;
}
