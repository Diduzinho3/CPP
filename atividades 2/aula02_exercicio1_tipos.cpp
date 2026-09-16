#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    char letra = 'A';
    int inteiro = 42;
    float decimal = 3.5f;
    double preciso = 3.14159;
    bool ativo = true;
    short pequeno = 100;
    long grande = 100000L;
    unsigned int natural = 200U;

    cout << left << boolalpha;
    cout << setw(16) << "Tipo" << setw(16) << "Valor" << "Tamanho (bytes)\n";
    cout << setw(16) << "char" << setw(16) << letra << sizeof(letra) << '\n';
    cout << setw(16) << "int" << setw(16) << inteiro << sizeof(inteiro) << '\n';
    cout << setw(16) << "float" << setw(16) << decimal << sizeof(decimal) << '\n';
    cout << setw(16) << "double" << setw(16) << preciso << sizeof(preciso) << '\n';
    cout << setw(16) << "bool" << setw(16) << ativo << sizeof(ativo) << '\n';
    cout << setw(16) << "short" << setw(16) << pequeno << sizeof(pequeno) << '\n';
    cout << setw(16) << "long" << setw(16) << grande << sizeof(grande) << '\n';
    cout << setw(16) << "unsigned int" << setw(16) << natural << sizeof(natural) << '\n';
    return 0;
}
