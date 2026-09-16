#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    int idade;
    float nota;
    cout << "Digite o nome completo: ";
    getline(cin, nome);
    if (nome.find_first_not_of(" \t\r") == string::npos) {
        cout << "Nome invalido.\n";
        return 1;
    }
    cout << "Digite a idade: ";
    if (!(cin >> idade) || idade < 0) {
        cout << "Idade invalida.\n";
        return 1;
    }
    cout << "Digite a nota final (use ponto decimal): ";
    if (!(cin >> nota) || !isfinite(nota)) {
        cout << "Nota invalida.\n";
        return 1;
    }
    string notaTexto = to_string(nota);
    cout << "Dados confirmados:\nNome: " << nome
         << "\nIdade: " << idade << " anos\nNota final: " << notaTexto << '\n';
    return 0;
}
