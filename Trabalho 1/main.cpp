#include <iostream>
#include <string>

using namespace std;

struct Funcionario {
    string nome;
    int codigo;
    float salario;
    int idade;
};

int main() {

    int maiorSalario = 0;
    int idSalario;
    int maisVelho = 0;
    int idVelho;
    float mediaSalarial = 0;

    Funcionario funcionarios[8] = {
        {"Jorge", 0b0001, 1250.00, 18},
        {"Maria", 0b0010, 2300.00, 25},
        {"Carlos", 0b0011, 1800.00, 32},
        {"Ana", 0b0100, 3200.00, 29},
        {"Pedro", 0b0101, 1500.00, 40},
        {"Lucas", 0b0110, 2800.00, 22},
        {"Julia", 0b0111, 2100.00, 35},
        {"Marcos", 0b1000, 1900.00, 45}
    };

    for(int i = 0; i < 8; i++) {
        if(maiorSalario < funcionarios[i].salario) {
            maiorSalario = funcionarios[i].salario;
            idSalario = i;
        }
    }

    for(int i = 0; i < 8; i++) {
        if(maisVelho < funcionarios[i].idade) {
            maisVelho = funcionarios[i].idade;
            idVelho = i;
        }
    }

    for(int i = 0; i < 8; i++) {
        mediaSalarial += funcionarios[i].salario;
    }
    mediaSalarial /= 8;

    cout << "Funcionario com maior salario: " << endl;
    cout << funcionarios[idSalario].nome << endl;
    cout << "\nFuncionario mais velho: " << endl;
    cout << funcionarios[idVelho].nome << endl;
    cout << "\nMedia salarial: " << endl;
    cout << mediaSalarial << endl;
    cout << "\nFuncionarios com salario acima da media: " << endl;
    for(int i = 0; i < 8; i++) {
        if(funcionarios[i].salario >= mediaSalarial) {
            cout << funcionarios[i].nome << endl;
        }
    };


    return 0;
}