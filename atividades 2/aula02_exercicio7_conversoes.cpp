#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    string texto;
    cout << "Digite um numero inteiro: ";
    getline(cin, texto);
    try {
        size_t posicao;
        int numero = stoi(texto, &posicao);
        if (texto.find_first_not_of(" \t\r", posicao) != string::npos) {
            throw invalid_argument("Caracteres apos o inteiro");
        }
        bool valorBooleano = static_cast<bool>(numero);
        bool positivoEPar = (numero > 0) && (numero % 2 == 0);
        cout << boolalpha;
        cout << "Inteiro convertido: " << numero << '\n';
        cout << "Inteiro convertido para bool: " << valorBooleano << '\n';
        cout << "O numero e positivo e par: " << positivoEPar << '\n';
    } catch (const invalid_argument&) {
        cout << "Entrada invalida: digite um numero inteiro.\n";
        return 1;
    } catch (const out_of_range&) {
        cout << "Numero fora da faixa do tipo int.\n";
        return 1;
    }
    return 0;
}
