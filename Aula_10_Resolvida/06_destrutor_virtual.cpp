// Aula 10 - Exercicio 6: liberacao segura pelo ponteiro da classe base.
#include <iostream>
#include <string>
using namespace std;

class Recurso {
public:
    virtual ~Recurso() {
        cout << "Destrutor Recurso: parte base liberada.\n";
    }
};

class RecursoArquivo : public Recurso {
private:
    char* buffer;
    string nome;
public:
    explicit RecursoArquivo(const string& arquivo)
        : buffer(new char[128]), nome(arquivo) {
        cout << "Construtor RecursoArquivo: buffer alocado para " << nome << ".\n";
    }

    ~RecursoArquivo() override {
        delete[] buffer;
        cout << "Destrutor RecursoArquivo: buffer de " << nome << " liberado.\n";
    }
};

int main() {
    Recurso* recurso = new RecursoArquivo("relatorio.txt");
    cout << "Excluindo o objeto atraves de Recurso*...\n";
    delete recurso;  // Primeiro chama ~RecursoArquivo, depois ~Recurso.
    return 0;
}
