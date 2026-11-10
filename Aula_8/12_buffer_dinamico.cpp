#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

class Buffer {
    size_t quantidade;
    int* dados;
public:
    explicit Buffer(size_t n) : quantidade(n), dados(n ? new int[n]{} : nullptr) {}
    ~Buffer() { delete[] dados; }

    Buffer(const Buffer& outro) : Buffer(outro.quantidade) {
        if (quantidade) copy_n(outro.dados, quantidade, dados); // Copia profunda.
    }
    Buffer& operator=(const Buffer& outro) {
        if (this != &outro) { Buffer temporario(outro); trocar(temporario); }
        return *this;
    }
    Buffer(Buffer&& outro) noexcept : quantidade(outro.quantidade), dados(outro.dados) {
        outro.quantidade = 0;
        outro.dados = nullptr;
    }
    Buffer& operator=(Buffer&& outro) noexcept {
        if (this != &outro) {
            delete[] dados;
            quantidade = outro.quantidade;
            dados = outro.dados;
            outro.quantidade = 0;
            outro.dados = nullptr;
        }
        return *this;
    }
    void trocar(Buffer& outro) noexcept {
        swap(quantidade, outro.quantidade);
        swap(dados, outro.dados);
    }
    size_t size() const { return quantidade; }
    int& at(size_t i) {
        if (i >= quantidade) throw out_of_range("Indice invalido");
        return dados[i];
    }
    const int& at(size_t i) const {
        if (i >= quantidade) throw out_of_range("Indice invalido");
        return dados[i];
    }
    Buffer operator+(const Buffer& outro) const {
        if (quantidade != outro.quantidade)
            throw invalid_argument("Buffers de tamanhos diferentes");
        Buffer soma(quantidade);
        for (size_t i = 0; i < quantidade; ++i) soma.dados[i] = dados[i] + outro.dados[i];
        return soma;
    }
    void mostrar() const {
        for (size_t i = 0; i < quantidade; ++i) cout << dados[i] << ' ';
        cout << '\n';
    }
};

int main() {
    Buffer a(3), b(3);
    for (size_t i = 0; i < 3; ++i) { a.at(i) = int(i + 1); b.at(i) = int((i + 1) * 10); }
    Buffer c = a; // Copia profunda.
    c.at(0) = 99;
    cout << "A original: "; a.mostrar();
    cout << "Copia alterada: "; c.mostrar();
    Buffer soma = a + b;
    cout << "Soma: "; soma.mostrar(); // 11 22 33
    Buffer movido = std::move(soma);
    cout << "Movido: "; movido.mostrar();
    cout << "Origem apos mover, tamanho: " << soma.size() << '\n';
    try { Buffer diferente(2); auto invalido = a + diferente; (void)invalido; }
    catch (const invalid_argument& e) { cout << "Erro esperado: " << e.what() << '\n'; }
}
