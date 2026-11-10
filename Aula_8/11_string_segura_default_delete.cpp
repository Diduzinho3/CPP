#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;

class StringSegura {
    unique_ptr<char[]> texto;
public:
    explicit StringSegura(const char* valor) {
        size_t n = strlen(valor);
        texto = make_unique<char[]>(n + 1);
        copy_n(valor, n + 1, texto.get());
    }
    // Recurso com posse exclusiva: movimentar e seguro e barato.
    StringSegura(StringSegura&&) noexcept = default;
    StringSegura& operator=(StringSegura&&) noexcept = default;
    StringSegura(const StringSegura&) = delete;
    StringSegura& operator=(const StringSegura&) = delete;
    const char* c_str() const { return texto ? texto.get() : ""; }
};

int main() {
    StringSegura a("Ola");
    StringSegura b(std::move(a)); // Permitido: construtor de movimento.
    StringSegura c("Outro");
    c = std::move(b); // Permitido: atribuicao por movimento.
    cout << "Valor movido: " << c.c_str() << '\n';
    // StringSegura erro = c; // Erro: construtor de copia deletado.
    // c = a;                 // Erro: atribuicao por copia deletada.
}
