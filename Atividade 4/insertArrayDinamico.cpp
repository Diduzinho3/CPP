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

    int novoValor;

    cout << "Novo valor: ";
    cin >> novoValor;

    int* novoArray = new int[quantidade + 1];

    for (int i = 0; i < quantidade; i++) {
        novoArray[i] = valores[i];
    }

    novoArray[quantidade] = novoValor;

    delete[] valores;

    valores = novoArray;

    quantidade++;

    cout << "\nArray final: ";

    for (int i = 0; i < quantidade; i++) {
        cout << valores[i] << " ";
    }

    cout << endl;

    delete[] valores;

    return 0;
}