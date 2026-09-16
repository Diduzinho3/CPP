#include <iostream>
using namespace std;

int contador = 100;

int main() {
    int contador = 10;
    cout << "Contador global: " << ::contador << '\n';
    cout << "Contador local do main: " << contador << '\n';
    if (true) {
        int contador = 1;
        cout << "Contador do bloco if: " << contador << '\n';
        cout << "Global acessado dentro do if: " << ::contador << '\n';
    }
    cout << "Contador local depois do if: " << contador << '\n';
    cout << "Contador global depois do if: " << ::contador << '\n';
    return 0;
}
