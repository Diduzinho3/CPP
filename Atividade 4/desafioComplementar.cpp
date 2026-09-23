#include <iostream>

using namespace std;

int main() {
    int quantidade;

    cout << "Quantidade de elementos: ";
    cin >> quantidade;

    int* valores = new int[quantidade];

    for (int i = 0; i < quantidade; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];
    }

    int posicao;

    cout << "\nArray atual:\n";

    for (int i = 0; i < quantidade; i++) {
        cout << i << " -> " << valores[i] << endl;
    }

    cout << "\nPosicao que deseja remover: ";
    cin >> posicao;

    if (posicao < 0 || posicao >= quantidade) {
        cout << "Posicao invalida!" << endl;

        delete[] valores;
        return 0;
    }

    int* novoArray = new int[quantidade - 1];

    int j = 0;

    for (int i = 0; i < quantidade; i++) {
        if (i != posicao) {
            novoArray[j] = valores[i];
            j++;
        }
    }

    delete[] valores;

    valores = novoArray;

    quantidade--;

    cout << "\nArray final: ";

    for (int i = 0; i < quantidade; i++) {
        cout << valores[i] << " ";
    }

    cout << endl;

    delete[] valores;

    return 0;
}