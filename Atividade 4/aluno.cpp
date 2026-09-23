#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    double nota1;
    double nota2;
    double nota3;
};

double calcularMedia(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
}

int main() {
    Aluno aluno;

    cout << "Nome: ";
    getline(cin, aluno.nome);

    cout << "Matricula: ";
    cin >> aluno.matricula;

    cout << "Nota 1: ";
    cin >> aluno.nota1;

    cout << "Nota 2: ";
    cin >> aluno.nota2;

    cout << "Nota 3: ";
    cin >> aluno.nota3;

    cout << "\nNome: " << aluno.nome << endl;
    cout << "Matricula: " << aluno.matricula << endl;
    cout << "Nota 1: " << aluno.nota1 << endl;
    cout << "Nota 2: " << aluno.nota2 << endl;
    cout << "Nota 3: " << aluno.nota3 << endl;
    cout << "Media: " << calcularMedia(aluno) << endl;

    return 0;
}