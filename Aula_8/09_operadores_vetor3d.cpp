#include <iostream>
using namespace std;

class Vetor3D {
    double x, y, z;
public:
    Vetor3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Vetor3D operator+(const Vetor3D& o) const {
        return Vetor3D(x + o.x, y + o.y, z + o.z);
    }
    double operator*(const Vetor3D& o) const {
        return x * o.x + y * o.y + z * o.z; // Produto escalar.
    }
    void mostrar() const { cout << '(' << x << ", " << y << ", " << z << ')'; }
};

int main() {
    Vetor3D a(1, 2, 3), b(4, 5, 6);
    cout << "a+b = "; (a + b).mostrar();
    cout << "\na*b = " << (a * b) << '\n'; // 32
}
