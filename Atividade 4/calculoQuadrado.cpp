#include <iostream>

using namespace std;

int calculaQuadrado(int valor) {
    return valor * valor;
}

double calculaQuadrado(double valor) {
    return valor * valor;
}

int main() {
    int inteiro;
    double decimal;

    cout << "Digite um numero inteiro: ";
    cin >> inteiro;

    cout << "Digite um numero decimal: ";
    cin >> decimal;

    cout << "Quadrado do inteiro: "
         << calculaQuadrado(inteiro) << endl;

    cout << "Quadrado do decimal: "
         << calculaQuadrado(decimal) << endl;

    return 0;
}