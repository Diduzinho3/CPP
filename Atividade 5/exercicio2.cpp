#include <iostream>

using namespace std;

int main() {
    double a[100];
    double *aPtr = a;

    int n;
    double soma = 0;

    cout << "Quantidade de valores: ";
    cin >> n;

    for(int j = 0; j < n; j++) {
        cout << "Valor " << j + 1 << ": ";
        cin >> *(a + j);
    }

    for(int j = 0; j < n; j++) {
        soma += *(aPtr + j);
    }

    double media = soma / n;

    cout << "Soma: " << soma << endl;
    cout << "Media: " << media << endl;

    return 0;
}
