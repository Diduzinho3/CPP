#include <iostream>
using namespace std;

// Uma copia desta struct duplica apenas o endereco; nenhum objeto e dono dele.
struct VisaoRasa { int* endereco; };

class DonoProfundo {
    int* dado;
public:
    explicit DonoProfundo(int valor) : dado(new int(valor)) {}
    DonoProfundo(const DonoProfundo& outro) : dado(new int(*outro.dado)) {}
    DonoProfundo& operator=(const DonoProfundo& outro) {
        if (this != &outro) { int* novo = new int(*outro.dado); delete dado; dado = novo; }
        return *this;
    }
    ~DonoProfundo() { delete dado; }
    int get() const { return *dado; }
    void set(int valor) { *dado = valor; }
};

int main() {
    int numero = 10;
    VisaoRasa a{&numero};
    VisaoRasa b = a; // Copia rasa: mesmo endereco.
    *b.endereco = 25;
    cout << "Copia rasa (mesmo endereco): " << *a.endereco << ", " << *b.endereco << '\n';

    DonoProfundo original(10);
    DonoProfundo copia = original; // Copia profunda: inteiros independentes.
    copia.set(25);
    cout << "Copia profunda: original=" << original.get() << ", copia=" << copia.get() << '\n';
    // Se dois proprietarios fizessem delete do mesmo ponteiro, haveria double-free.
}
