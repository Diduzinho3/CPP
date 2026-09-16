#include <cmath>
#include <iomanip>
#include <iostream>
#define TAXA_JUROS 0.05
using namespace std;

int main() {
    const int ANOS = 3;
    double capital;
    cout << "Digite o capital inicial (use ponto decimal): R$ ";
    if (!(cin >> capital) || !isfinite(capital) || capital < 0) {
        cout << "Capital invalido.\n";
        return 1;
    }
    double montante = capital * (1 + TAXA_JUROS * ANOS);
    if (!isfinite(montante)) {
        cout << "Valor muito alto para calcular.\n";
        return 1;
    }
    double rendimento = montante - capital;
    cout << fixed << setprecision(2);
    cout << "Capital inicial: R$ " << capital << '\n';
    cout << "Montante apos " << ANOS << " anos: R$ " << montante << '\n';
    cout << "Diferenca (juros recebidos): R$ " << rendimento << '\n';
    return 0;
}
