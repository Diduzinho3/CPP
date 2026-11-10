#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

int main() {
    No* primeiro = nullptr;
    No* ultimo = nullptr;

    for (int i = 1; i <= 5; ++i) {
        int valor;
        cout << "Digite o valor do no " << i << ": ";
        if (!(cin >> valor)) {
            // Mesmo com falha de entrada, os nos existentes sao liberados abaixo.
            break;
        }
        No* novo = new No{valor, nullptr};
        if (primeiro == nullptr) primeiro = novo;
        else ultimo->proximo = novo;
        ultimo = novo;
    }

    cout << "Lista: ";
    for (No* atual = primeiro; atual != nullptr; atual = atual->proximo)
        cout << atual->valor << ' ';
    cout << '\n';

    while (primeiro != nullptr) {
        No* proximo = primeiro->proximo;
        delete primeiro; // Libera cada no individualmente.
        primeiro = proximo;
    }
    ultimo = nullptr;
    cout << "Memoria liberada.\n";
    return 0;
}
