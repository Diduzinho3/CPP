// Aula 10 - Exercicio 5: classe abstrata e funcoes virtuais puras.
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class FormaGeometrica {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual string nome() const = 0;
    virtual ~FormaGeometrica() = default;
};

class Retangulo : public FormaGeometrica {
private:
    double largura, altura;
public:
    Retangulo(double l, double a) : largura(l), altura(a) {}
    double calcularArea() const override { return largura * altura; }
    double calcularPerimetro() const override { return 2 * (largura + altura); }
    string nome() const override { return "Retangulo"; }
};

class Circulo : public FormaGeometrica {
private:
    double raio;
public:
    explicit Circulo(double r) : raio(r) {}
    double calcularArea() const override {
        const double PI = acos(-1.0);
        return PI * raio * raio;
    }
    double calcularPerimetro() const override {
        const double PI = acos(-1.0);
        return 2 * PI * raio;
    }
    string nome() const override { return "Circulo"; }
};

int main() {
    // FormaGeometrica forma; // ERRO: classe abstrata nao pode ser instanciada.
    vector<unique_ptr<FormaGeometrica>> formas;
    formas.push_back(make_unique<Retangulo>(4.0, 3.0));
    formas.push_back(make_unique<Circulo>(2.0));
    formas.push_back(make_unique<Retangulo>(5.0, 2.0));

    cout << fixed << setprecision(2);
    for (const auto& forma : formas) {
        cout << forma->nome() << " | Area: " << forma->calcularArea()
             << " | Perimetro: " << forma->calcularPerimetro() << '\n';
    }
    // unique_ptr destroi os objetos automaticamente.
    return 0;
}
