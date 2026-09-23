#include <iostream>

using namespace std;

int main() {
    int quantidade;

    cout << "Quantidade de elementos: ";
    cin >> quantidade;

    double* valores = new double[quantidade];

    double soma = 0;

    for (int i = 0; i < quantidade; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valores[i];

        soma += valores[i];
    }

    double media = soma / quantidade;

    cout << "\nMedia: " << media << endl;

    delete[] valores;

    return 0;
}