#include <iostream>
using namespace std;

// Nomes dos parametros nao distinguem sobrecargas: (double,double)
// serve tanto para retangulo quanto para triangulo. Um terceiro parametro-tag
// diferencia a assinatura do triangulo sem ambiguidade.
struct TrianguloTag {};

double calcularArea(double lado) { return lado * lado; }
double calcularArea(double largura, double altura) { return largura * altura; }
double calcularArea(double base, double altura, TrianguloTag) { return base * altura / 2; }

int main() {
    cout << "Quadrado: " << calcularArea(4.0) << '\n';
    cout << "Retangulo: " << calcularArea(4.0, 3.0) << '\n';
    cout << "Triangulo: " << calcularArea(4.0, 3.0, TrianguloTag{}) << '\n';
    // Apenas trocar double por int no retorno NAO cria sobrecarga.
}
