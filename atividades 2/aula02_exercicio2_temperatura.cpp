#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    double celsius;
    cout << "Digite a temperatura em Celsius (use ponto decimal): ";
    if (!(cin >> celsius) || !isfinite(celsius)) {
        cout << "Temperatura invalida.\n";
        return 1;
    }
    double fahrenheit = celsius * 1.8 + 32;
    double kelvin = celsius + 273.15;
    if (!isfinite(fahrenheit) || fahrenheit < numeric_limits<int>::min()
        || fahrenheit > numeric_limits<int>::max()) {
        cout << "Temperatura fora da faixa para conversao em inteiro.\n";
        return 1;
    }
    int fahrenheitInteiro = static_cast<int>(fahrenheit);
    cout << fixed << setprecision(2);
    cout << "Fahrenheit: " << fahrenheit << " F\n";
    cout << "Kelvin: " << kelvin << " K\n";
    cout << "Fahrenheit inteiro (sem arredondar): " << fahrenheitInteiro << '\n';
    return 0;
}
