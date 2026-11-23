// Aula 10 - Exercicio 8: heranca, abstracao, polimorfismo e aberto/fechado.
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Notificacao {
public:
    virtual void enviar() const = 0;
    virtual ~Notificacao() = default;
};

class Email : public Notificacao {
private:
    string destinatario;
    string mensagem;
public:
    Email(const string& d, const string& m) : destinatario(d), mensagem(m) {}
    void enviar() const override {
        cout << "Email para " << destinatario << ": " << mensagem << '\n';
    }
};

class SMS : public Notificacao {
private:
    string numero;
    string mensagem;
public:
    SMS(const string& n, const string& m) : numero(n), mensagem(m) {}
    void enviar() const override {
        cout << "SMS para " << numero << ": " << mensagem << '\n';
    }
};

class NotificacaoPush : public Notificacao {
private:
    string aplicativo;
    string mensagem;
public:
    NotificacaoPush(const string& a, const string& m)
        : aplicativo(a), mensagem(m) {}
    void enviar() const override {
        cout << "Push em " << aplicativo << ": " << mensagem << '\n';
    }
};

int main() {
    vector<unique_ptr<Notificacao>> notificacoes;
    notificacoes.push_back(make_unique<Email>("aluno@exemplo.com", "Aula iniciada"));
    notificacoes.push_back(make_unique<SMS>("(66) 99999-0000", "Sua senha chegou"));
    notificacoes.push_back(make_unique<NotificacaoPush>("Agenda", "Trabalho para entregar"));

    // O laco nao precisa conhecer os tipos concretos.
    for (const auto& notificacao : notificacoes) {
        notificacao->enviar();
    }
    // Esses envios sao simulados: mensagens aparecem no terminal.
    return 0;
}
