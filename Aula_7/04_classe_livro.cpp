#include <iostream>
#include <string>
using namespace std;

class Livro {
private:
    string titulo;
    string autor;
    int paginas;

public:
    Livro(string titulo, string autor, int paginas)
        : titulo(titulo), autor(autor), paginas(1) {
        setPaginas(paginas);
    }

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getPaginas() const { return paginas; }

    bool setTitulo(string novoTitulo) {
        if (novoTitulo.empty()) return false;
        titulo = novoTitulo;
        return true;
    }
    bool setAutor(string novoAutor) {
        if (novoAutor.empty()) return false;
        autor = novoAutor;
        return true;
    }
    bool setPaginas(int novasPaginas) {
        if (novasPaginas <= 0) return false;
        paginas = novasPaginas;
        return true;
    }
};

int main() {
    Livro livros[3] = {
        Livro("O Mundo de Sofia", "Jostein Gaarder", 560),
        Livro("Dom Casmurro", "Machado de Assis", 256),
        Livro("O Hobbit", "J. R. R. Tolkien", 310)
    };

    for (const Livro& livro : livros) {
        cout << "Titulo: " << livro.getTitulo()
             << " | Autor: " << livro.getAutor()
             << " | Paginas: " << livro.getPaginas() << '\n';
    }
    return 0;
}
