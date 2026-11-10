#include <iostream>
using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    Ponto() : x(0), y(0) {}
    Ponto(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }
};

int main() {
    Ponto origem;
    Ponto posicao(3.5, -2.0);
    cout << "Ponto sem argumentos: (" << origem.getX() << ", " << origem.getY() << ")\n";
    cout << "Ponto com argumentos: (" << posicao.getX() << ", " << posicao.getY() << ")\n";
    return 0;
}
