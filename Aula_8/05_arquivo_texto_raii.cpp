#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ArquivoTexto {
    ofstream arquivo;
public:
    explicit ArquivoTexto(const string& caminho) : arquivo(caminho) {
        if (!arquivo.is_open()) {
            cerr << "Falha ao abrir: " << caminho << '\n';
            throw runtime_error("Nao foi possivel abrir o arquivo");
        }
        cout << "Arquivo aberto.\n";
    }
    void escrever(const string& texto) {
        if (!(arquivo << texto << '\n')) throw runtime_error("Falha na escrita");
    }
    ~ArquivoTexto() {
        if (arquivo.is_open()) {
            arquivo.close();
            cout << "Arquivo fechado automaticamente no destrutor.\n";
        }
    }
};

int main() {
    try {
        cout << "Inicio do bloco.\n";
        {
            ArquivoTexto saida("saida_aula8.txt");
            saida.escrever("Demonstracao de RAII e destrutor.");
        }
        cout << "Fim do bloco: o destrutor ja foi chamado.\n";
    } catch (const exception& erro) {
        cerr << erro.what() << '\n';
        return 1;
    }
}
