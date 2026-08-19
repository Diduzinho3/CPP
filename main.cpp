#include <iostream>

using namespace std;

int main() {

    cout << "Aprender C++ e taooo divertido!" << endl;

    string nome;
    string cidade;

    nome = "Eduardo";
    cidade = "Barra do Garcas";

    cout << nome << endl
         << cidade << endl;

    float variavel;

    cout << "Digite um numero: ";
    cin >> variavel;
    cout << "Valor novo: " << variavel * 2 << endl;

    int triplo;

    cout << "Digite um numero inteiro: ";
    cin >> triplo;
    cout << "Valor novo: " << triplo * 3 << endl;

    int a;
    int b;

    cout << "Digite o valor 'a': ";
    cin >> a;
    cout << "Digite o valor 'b': ";
    cin >> b;
    cout << "A soma dos numeros e: " << a + b << endl;

    int c;
    int d;

    cout << "Digite o valor 'c': ";
    cin >> c;
    cout << "Digite o valor 'd': ";
    cin >> d;
    cout << "A diferenca dos numeros e: " << c - d << endl;

    int f;
    int g;

    cout << "Digite o valor 'f': ";
    cin >> f;
    cout << "Digite o valor 'g': ";
    cin >> g;
    cout << "A multiplicacao dos numeros e: " << f * g << endl;

    return 0;
}