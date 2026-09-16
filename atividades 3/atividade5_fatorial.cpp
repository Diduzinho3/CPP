#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Digite um numero inteiro de 0 a 20: ";
    if (!(cin >> numero) || numero < 0 || numero > 20) {
        cout << "Numero invalido. Digite um inteiro entre 0 e 20.\n";
        return 1;
    }

    unsigned long long fatorial = 1;
    for (int i = 2; i <= numero; i++) {
        fatorial *= i;
    }
    cout << numero << "! = " << fatorial << "\n";
    return 0;
}
