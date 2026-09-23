#include <iostream>

using namespace std;

inline double converter(double dolar, double cotacao) {
    return dolar * cotacao;
}

int main() {
    double dolares, cotacao;

    cout << "Quantidade em dolares: ";
    cin >> dolares;

    cout << "Cotacao do dolar: ";
    cin >> cotacao;

    cout << "Valor em reais: R$ "
         << converter(dolares, cotacao) << endl;

    return 0;
}