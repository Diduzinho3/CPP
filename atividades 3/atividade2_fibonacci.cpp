#include <iostream>
using namespace std;

int main() {
    long long limite;
    cout << "Digite um numero inteiro nao negativo: ";
    if (!(cin >> limite) || limite < 0) {
        cout << "Numero invalido.\n";
        return 1;
    }

    long long anterior = 0, atual = 1;
    cout << "Fibonacci ate " << limite << ": 0";
    while (atual <= limite) {
        cout << " " << atual;
        if (anterior > limite - atual) {
            break;
        }
        long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    cout << "\n";
    return 0;
}
