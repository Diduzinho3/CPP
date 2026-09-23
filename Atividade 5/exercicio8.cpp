#include <iostream>

using namespace std;

int multiplicar(int a, int b) {
    return a * b;
}

int somar(int a, int b) {
    return a + b;
}

int main() {
    int a = 10;
    int b = 5;

    int (*operacao)(int, int);

    operacao = somar;

    cout << "Soma: " << operacao(a, b) << endl;

    operacao = multiplicar;

    cout << "Multiplicacao: " << operacao(a, b) << endl;

    return 0;
}
