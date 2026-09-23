#include <iostream>

using namespace std;

int soma(int a, int b) {
    return a + b;
}

int main() {
    int valor1, valor2;

    cout << "Primeiro valor: ";
    cin >> valor1;

    cout << "Segundo valor: ";
    cin >> valor2;

    cout << "Soma: " << soma(valor1, valor2) << endl;

    return 0;
}