#include <iostream>
#include <string>
using namespace std;

// Versao insegura: qualquer codigo pode atribuir uma nota invalida.
struct AlunoSemEncapsulamento {
    string nome;
    double nota;
};

// Versao corrigida: acesso publico somente por metodos controlados.
class Aluno {
private:
    string nome;
    double nota;

public:
    Aluno(string nome, double nota) : nome(nome), nota(0) {
        setNota(nota);
    }

    string getNome() const { return nome; }
    double getNota() const { return nota; }

    bool setNota(double novaNota) {
        if (novaNota < 0 || novaNota > 10) return false;
        nota = novaNota;
        return true;
    }
};

int main() {
    AlunoSemEncapsulamento antigo = {"Ana", 8};
    antigo.nota = 15; // Permitido, mas fora do intervalo correto.
    cout << "Sem encapsulamento, nota invalida: " << antigo.nota << '\n';

    Aluno protegido("Ana", 8);
    if (!protegido.setNota(15)) cout << "Nota 15 rejeitada!\n";
    cout << "Com encapsulamento: " << protegido.getNome()
         << " - nota valida: " << protegido.getNota() << '\n';
    // protegido.nota = 15; // ERRO de compilacao: nota e privada.
    return 0;
}
