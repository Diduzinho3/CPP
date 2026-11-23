// Aula 10 - Exercicio 3: acesso public, protected e private.
#include <iostream>
#include <string>
using namespace std;

class Funcionario {
public:
    string nome;

protected:
    double salario;

private:
    string documento;

public:
    Funcionario(const string& n, double s, const string& d)
        : nome(n), salario(s), documento(d) {}

    // A propria classe pode ler atributos privados e protegidos.
    void mostrarDocumento() const {
        cout << "Documento (via metodo publico): " << documento << '\n';
    }
};

class Gerente : public Funcionario {
public:
    Gerente(const string& n, double s, const string& d)
        : Funcionario(n, s, d) {}

    void mostrarDados() const {
        cout << "Nome (public): " << nome << '\n';
        cout << "Salario (protected): R$ " << salario << '\n';

        // NAO COMPILA: 'documento' e private em Funcionario.
        // cout << documento << '\n';
    }

    void reajustarSalario(double percentual) {
        salario *= 1.0 + percentual / 100.0;  // Permitido na derivada.
    }
};

int main() {
    Gerente gerente("Ana", 5000.0, "DOC-123");

    cout << "Acesso pelo main - nome: " << gerente.nome << '\n';
    gerente.mostrarDados();
    gerente.mostrarDocumento();
    gerente.reajustarSalario(10);
    cout << "Apos reajuste de 10%:\n";
    gerente.mostrarDados();

    // Tentativas de acesso proibidas no main (descomente para ver o erro):
    // cout << gerente.salario;    // ERRO: protected.
    // cout << gerente.documento;  // ERRO: private.
    return 0;
}
