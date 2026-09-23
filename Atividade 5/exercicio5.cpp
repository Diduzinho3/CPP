#include <iostream>

using namespace std;

int main() {
    float *numero = new float;

    cout << "Digite um valor: ";
    cin >> *numero;

    cout << "Quadrado: " << (*numero) * (*numero) << endl;

    delete numero;

    return 0;
}
