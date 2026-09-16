#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double salario;
    cout << "Digite o salario (use ponto para os centavos): R$ ";
    if (!(cin >> salario) || !isfinite(salario) || salario < 0) {
        cout << "Salario invalido.\n";
        return 1;
    }

    int percentual;
    if (salario < 3000) {
        percentual = 50;
    } else if (salario <= 10000) {
        percentual = 20;
    } else {
        percentual = 15;
    }

    double aumento = salario * (percentual / 100.0);
    double novoSalario = salario + aumento;
    if (!isfinite(novoSalario)) {
        cout << "Salario muito alto para calcular.\n";
        return 1;
    }
    cout << fixed << setprecision(2);
    cout << "Reajuste: " << percentual << "%\n";
    cout << "Valor do aumento: R$ " << aumento << "\n";
    cout << "Novo salario: R$ " << novoSalario << "\n";
    return 0;
}
