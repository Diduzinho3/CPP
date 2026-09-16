#include <iostream>
using namespace std;

int main() {
    int idade;
    cout << "Digite a idade em anos completos: ";
    if (!(cin >> idade) || idade < 0) {
        cout << "Idade invalida.\n";
        return 1;
    }

    if (idade <= 1) {
        cout << "Bebe\n";
    } else if (idade <= 10) {
        cout << "Crianca\n";
    } else if (idade <= 17) {
        cout << "Adolescente\n";
    } else if (idade <= 64) {
        cout << "Adulto\n";
    } else if (idade <= 100) {
        cout << "Idoso\n";
    } else {
        cout << "Idade fora das faixas informadas na atividade.\n";
    }
    return 0;
}
