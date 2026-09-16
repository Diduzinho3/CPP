#include <iostream>
using namespace std;

int main() {
    int ano;
    cout << "Digite um ano: ";
    if (!(cin >> ano) || ano <= 0) {
        cout << "Ano invalido.\n";
        return 1;
    }

    if (ano >= 1930 && (ano - 1930) % 4 == 0) {
        cout << ano << " e um ano de Copa do Mundo.\n";
    } else {
        cout << ano << " nao e um ano de Copa do Mundo.\n";
    }
    return 0;
}
