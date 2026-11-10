#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

class MatrizDinamica {
private:
    int linhas, colunas;
    int** dados;

    void liberar() noexcept {
        for (int i = 0; i < linhas; ++i) delete[] dados[i];
        delete[] dados;
    }

public:
    MatrizDinamica(int l, int c) : linhas(l), colunas(c), dados(nullptr) {
        if (l <= 0 || c <= 0) throw invalid_argument("Dimensoes invalidas");
        dados = new int*[linhas]{};
        try {
            for (int i = 0; i < linhas; ++i) dados[i] = new int[colunas]{};
        } catch (...) {
            liberar();
            throw;
        }
    }

    // Cada objeto recebe suas proprias linhas e seus proprios valores.
    MatrizDinamica(const MatrizDinamica& outra)
        : MatrizDinamica(outra.linhas, outra.colunas) {
        for (int i = 0; i < linhas; ++i)
            for (int j = 0; j < colunas; ++j) dados[i][j] = outra.dados[i][j];
    }

    MatrizDinamica& operator=(const MatrizDinamica& outra) {
        if (this != &outra) {
            MatrizDinamica copia(outra);
            swap(linhas, copia.linhas);
            swap(colunas, copia.colunas);
            swap(dados, copia.dados);
        }
        return *this;
    }

    ~MatrizDinamica() { liberar(); }

    int& at(int i, int j) {
        if (i < 0 || i >= linhas || j < 0 || j >= colunas)
            throw out_of_range("Indice fora da matriz");
        return dados[i][j];
    }
    int at(int i, int j) const {
        if (i < 0 || i >= linhas || j < 0 || j >= colunas)
            throw out_of_range("Indice fora da matriz");
        return dados[i][j];
    }
    void mostrar() const {
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) cout << at(i, j) << ' ';
            cout << '\n';
        }
    }
};

int main() {
    MatrizDinamica original(2, 2);
    original.at(0, 0) = 1; original.at(0, 1) = 2;
    original.at(1, 0) = 3; original.at(1, 1) = 4;
    MatrizDinamica copia = original; // Construtor de copia profunda.
    copia.at(0, 0) = 999;
    cout << "Original:\n"; original.mostrar();
    cout << "Copia modificada:\n"; copia.mostrar();
    return 0;
}
