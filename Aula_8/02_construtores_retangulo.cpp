#include <iostream>
#include <stdexcept>
using namespace std;

class Retangulo {
    double largura, altura;
public:
    Retangulo() : largura(1), altura(1) {}
    Retangulo(double l, double a) : largura(l), altura(a) { validar(); }
    explicit Retangulo(double lado) : largura(lado), altura(lado) { validar(); }
    void validar() const {
        if (largura <= 0 || altura <= 0) throw invalid_argument("Dimensoes devem ser positivas");
    }
    double area() const { return largura * altura; }
    double perimetro() const { return 2 * (largura + altura); }
};

int main() {
    Retangulo a, b(4, 3), c(5);
    cout << "Padrao: area=" << a.area() << ", perimetro=" << a.perimetro() << '\n';
    cout << "Parametrizado: area=" << b.area() << ", perimetro=" << b.perimetro() << '\n';
    cout << "Quadrado: area=" << c.area() << ", perimetro=" << c.perimetro() << '\n';
}
