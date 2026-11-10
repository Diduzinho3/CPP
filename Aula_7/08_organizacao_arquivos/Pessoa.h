#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade);
    void apresentar() const;
};

#endif
