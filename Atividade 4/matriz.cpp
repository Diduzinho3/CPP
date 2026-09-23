#include <iostream>

using namespace std;

const int ANO = 2;
const int TRIMESTRE = 4;

int main() {
    double despesas[ANO][TRIMESTRE];
    double total = 0;

    for (int i = 0; i < ANO; i++) {
        cout << "\nAno " << i + 1 << endl;

        for (int j = 0; j < TRIMESTRE; j++) {
            cout << "Despesa do trimestre " << j + 1 << ": R$ ";
            cin >> despesas[i][j];

            total += despesas[i][j];
        }
    }

    cout << "\nTabela de despesas\n";

    for (int i = 0; i < ANO; i++) {
        cout << "\nAno " << i + 1 << ":" << endl;

        for (int j = 0; j < TRIMESTRE; j++) {
            cout << "Trimestre " << j + 1
                 << ": R$ " << despesas[i][j] << endl;
        }
    }

    cout << "\nTotal geral: R$ " << total << endl;

    return 0;
}