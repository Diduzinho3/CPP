#include <iomanip>
#include <iostream>

namespace Geometria {
    namespace Retangulo {
        double calcularArea(double b, double h) {
            return b * h;
        }
    }
    namespace Circulo {
        const double PI = 3.14159;
        double calcularArea(double r) {
            return PI * r * r;
        }
    }
}

int main() {
    const double base = 5.0, altura = 3.0, raio = 2.0;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Base = 5, altura = 3, raio = 2\n";

    std::cout << "Nome totalmente qualificado:\n";
    std::cout << "Retangulo: " << Geometria::Retangulo::calcularArea(base, altura) << '\n';
    std::cout << "Circulo: " << Geometria::Circulo::calcularArea(raio) << '\n';

    {
        using Geometria::Retangulo::calcularArea;
        using Geometria::Circulo::calcularArea;
        std::cout << "Declaracao using especifica:\n";
        std::cout << "Retangulo: " << calcularArea(base, altura) << '\n';
        std::cout << "Circulo: " << calcularArea(raio) << '\n';
    }
    {
        using namespace Geometria::Retangulo;
        using namespace Geometria::Circulo;
        std::cout << "Diretiva using namespace:\n";
        std::cout << "Retangulo: " << calcularArea(base, altura) << '\n';
        std::cout << "Circulo: " << calcularArea(raio) << '\n';
    }
    return 0;
}
