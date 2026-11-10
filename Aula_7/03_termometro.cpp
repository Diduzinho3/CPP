#include <iostream>
#include <iomanip>
using namespace std;

class Termometro {
private:
    double temperaturaCelsius;

public:
    Termometro() : temperaturaCelsius(25.0) {}

    bool setTemperaturaCelsius(double temperatura) {
        if (temperatura < -273.15) return false;
        temperaturaCelsius = temperatura;
        return true;
    }

    double getTemperaturaCelsius() const { return temperaturaCelsius; }

    double getTemperaturaFahrenheit() const {
        return temperaturaCelsius * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    Termometro t;
    cout << fixed << setprecision(2);
    cout << "Inicial: " << t.getTemperaturaCelsius() << " C = "
         << t.getTemperaturaFahrenheit() << " F\n";
    t.setTemperaturaCelsius(100);
    cout << "Atualizada: " << t.getTemperaturaCelsius() << " C = "
         << t.getTemperaturaFahrenheit() << " F\n";
    if (!t.setTemperaturaCelsius(-300)) cout << "Temperatura abaixo do zero absoluto!\n";
    cout << "Depois da tentativa: " << t.getTemperaturaCelsius() << " C\n";
    return 0;
}
