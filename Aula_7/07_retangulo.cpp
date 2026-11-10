#include <iostream>
using namespace std;

class Retangulo {
private:
    double largura;
    double altura;

public:
    Retangulo(double largura, double altura) : largura(1), altura(1) {
        setLargura(largura);
        setAltura(altura);
    }

    double getLargura() const { return largura; }
    double getAltura() const { return altura; }

    bool setLargura(double novaLargura) {
        if (novaLargura <= 0) return false;
        largura = novaLargura;
        return true;
    }
    bool setAltura(double novaAltura) {
        if (novaAltura <= 0) return false;
        altura = novaAltura;
        return true;
    }

    double calcularArea() const { return largura * altura; }
    double calcularPerimetro() const { return 2 * (largura + altura); }
};

int main() {
    Retangulo a(4, 5);
    Retangulo b(2, 6);
    cout << "Retangulo A (" << a.getLargura() << " x " << a.getAltura()
         << "): area = " << a.calcularArea() << ", perimetro = " << a.calcularPerimetro() << '\n';
    cout << "Retangulo B (" << b.getLargura() << " x " << b.getAltura()
         << "): area = " << b.calcularArea() << ", perimetro = " << b.calcularPerimetro() << '\n';
    cout << "Maior area: " << (a.calcularArea() > b.calcularArea() ? "A" : "B") << '\n';
    if (!a.setAltura(-3)) cout << "Altura negativa rejeitada!\n";
    cout << "Altura de A continua: " << a.getAltura() << '\n';
    return 0;
}
