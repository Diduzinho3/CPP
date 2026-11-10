#include <iostream>
#include <iomanip>
using namespace std;

class ContaBancaria {
private:
    int numeroConta;
    double saldo;

public:
    explicit ContaBancaria(int numeroConta)
        : numeroConta(numeroConta), saldo(0.0) {}

    int getNumeroConta() const { return numeroConta; }
    double getSaldo() const { return saldo; }

    bool depositar(double valor) {
        if (valor <= 0) return false;
        saldo += valor;
        return true;
    }

    bool sacar(double valor) {
        if (valor <= 0 || valor > saldo) return false;
        saldo -= valor;
        return true;
    }
};

int main() {
    ContaBancaria conta(12345);
    cout << fixed << setprecision(2);
    cout << "Conta: " << conta.getNumeroConta() << " | Saldo inicial: R$ " << conta.getSaldo() << '\n';

    cout << "Deposito de R$ 200: " << (conta.depositar(200) ? "aceito" : "recusado") << '\n';
    cout << "Deposito de R$ -10: " << (conta.depositar(-10) ? "aceito" : "recusado") << '\n';
    cout << "Saque de R$ 250: " << (conta.sacar(250) ? "aceito" : "recusado") << '\n';
    cout << "Saque de R$ 50: " << (conta.sacar(50) ? "aceito" : "recusado") << '\n';
    cout << "Saldo final: R$ " << conta.getSaldo() << '\n';
    return 0;
}
