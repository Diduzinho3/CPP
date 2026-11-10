#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string frase, palavra;
    stack<string> pilha;

    cout << "Digite uma frase: ";
    getline(cin, frase);
    istringstream entrada(frase);
    while (entrada >> palavra) pilha.push(palavra);

    cout << "Frase com palavras invertidas: ";
    bool primeira = true;
    while (!pilha.empty()) {
        if (!primeira) cout << ' ';
        cout << pilha.top();
        pilha.pop();
        primeira = false;
    }
    cout << '\n';
    // Como a pilha e LIFO, a ultima palavra inserida sai primeiro.
    return 0;
}
