#include <iostream>
#include <memory>
using namespace std;

int main() {
    // O unique_ptr assume a posse do inteiro criado.
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << "Valor: " << *ptr << '\n';
    // Ao sair do escopo, ptr e seu inteiro sao destruidos automaticamente.
    return 0;
}
