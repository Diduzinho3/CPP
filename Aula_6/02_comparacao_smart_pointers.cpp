#include <iostream>
#include <memory>
#include <utility>
using namespace std;

int main() {
    // unique_ptr: um unico dono por vez.
    unique_ptr<int> exclusivo = make_unique<int>(10);
    cout << "unique_ptr (antes): " << *exclusivo << '\n';
    unique_ptr<int> novoDono = move(exclusivo);
    cout << "Ponteiro antigo vazio? " << boolalpha << (exclusivo == nullptr) << '\n';
    cout << "Novo dono: " << *novoDono << '\n';

    // shared_ptr: varios donos, com contagem de referencias.
    shared_ptr<int> compartilhado = make_shared<int>(25);
    weak_ptr<int> observador = compartilhado; // Nao aumenta use_count().
    cout << "Referencias iniciais: " << compartilhado.use_count() << '\n';
    {
        shared_ptr<int> outroDono = compartilhado;
        cout << "Referencias com dois donos: " << compartilhado.use_count() << '\n';
        if (auto acesso = observador.lock()) {
            cout << "weak_ptr encontrou: " << *acesso << '\n';
        }
    }
    cout << "Referencias apos o bloco: " << compartilhado.use_count() << '\n';
    compartilhado.reset(); // O objeto nao tem mais donos.
    if (auto acesso = observador.lock()) {
        cout << "Ainda existe: " << *acesso << '\n';
    } else {
        cout << "Objeto destruido: lock() retornou vazio.\n";
    }
    return 0;
}
