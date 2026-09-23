#include <iostream>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

int main() {
    Data data;

    cout << "Dia: ";
    cin >> data.dia;

    cout << "Mes: ";
    cin >> data.mes;

    cout << "Ano: ";
    cin >> data.ano;

    cout << "\nData armazenada: "
         << data.dia << "/"
         << data.mes << "/"
         << data.ano << endl;

    return 0;
}