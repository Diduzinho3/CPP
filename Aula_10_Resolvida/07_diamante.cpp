// Aula 10 - Exercicio 7: compare com e sem -DSEM_HERANCA_VIRTUAL.
#include <iostream>
using namespace std;

class Dispositivo {
public:
    int identificador = 0;
    void exibirIdentificador() const {
        cout << "Identificador: " << identificador << '\n';
    }
};

#ifdef SEM_HERANCA_VIRTUAL
class Impressora : public Dispositivo {};
class Scanner : public Dispositivo {};
#else
class Impressora : virtual public Dispositivo {};
class Scanner : virtual public Dispositivo {};
#endif

class Multifuncional : public Impressora, public Scanner {};

int main() {
    Multifuncional aparelho;
    Dispositivo* viaImpressora = static_cast<Impressora*>(&aparelho);
    Dispositivo* viaScanner = static_cast<Scanner*>(&aparelho);

    cout << boolalpha;
    cout << "Mesma instancia de Dispositivo? "
         << (viaImpressora == viaScanner) << '\n';

#ifdef SEM_HERANCA_VIRTUAL
    // aparelho.identificador = 10;  // ERRO: ambiguidade (duas bases).
    // aparelho.exibirIdentificador(); // ERRO: chamada ambigua.
    aparelho.Impressora::identificador = 101;
    aparelho.Scanner::identificador = 202;
    cout << "Via Impressora: ";
    aparelho.Impressora::exibirIdentificador();
    cout << "Via Scanner: ";
    aparelho.Scanner::exibirIdentificador();
#else
    aparelho.identificador = 303;  // Apenas uma base compartilhada.
    aparelho.exibirIdentificador();
#endif
    return 0;
}
