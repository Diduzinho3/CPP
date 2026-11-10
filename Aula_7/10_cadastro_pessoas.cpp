#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    Pessoa(string nome, int idade) : nome(nome), idade(0) {
        setIdade(idade);
    }

    string getNome() const { return nome; }
    int getIdade() const { return idade; }

    bool setIdade(int novaIdade) {
        if (novaIdade < 0) return false;
        idade = novaIdade;
        return true;
    }
};

int main() {
    int quantidade;
    cout << "Quantas pessoas deseja cadastrar? ";
    if (!(cin >> quantidade) || quantidade <= 0) {
        cout << "Quantidade invalida.\n";
        return 0;
    }

    vector<Pessoa> pessoas;
    for (int i = 0; i < quantidade; ++i) {
        string nome;
        int idade;
        cout << "\nNome da pessoa " << i + 1 << ": ";
        getline(cin >> ws, nome);
        do {
            cout << "Idade (nao negativa): ";
            if (!(cin >> idade)) return 0;
            if (idade < 0) cout << "Idade invalida!\n";
        } while (idade < 0);
        pessoas.emplace_back(nome, idade);
    }

    cout << "\n--- Pessoas cadastradas ---\n";
    for (const Pessoa& pessoa : pessoas) {
        cout << pessoa.getNome() << " - " << pessoa.getIdade() << " anos\n";
    }
    // O setter tambem impede alteracoes invalidas apos o cadastro.
    if (!pessoas[0].setIdade(-1)) cout << "Alteracao para idade negativa rejeitada.\n";
    return 0;
}
