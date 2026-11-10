# Exercício 9 — Compilação e linker

- **Pessoa.h** declara a classe `Pessoa`, seus atributos e as assinaturas dos métodos. As diretivas `#ifndef`, `#define` e `#endif` impedem que o mesmo cabeçalho seja incluído várias vezes na mesma unidade de tradução.
- **main.cpp inclui `Pessoa.h`** para que o compilador conheça a declaração da classe, seus construtores e métodos, sem precisar copiar sua implementação.
- **Pessoa.cpp** contém as definições do construtor e de `apresentar()`.
- **Linker** (ligador) combina o código-objeto gerado de `main.cpp` e `Pessoa.cpp`, resolvendo as referências às funções declaradas no cabeçalho e definidas em outro arquivo. Se `Pessoa.cpp` não for incluído na compilação, podem ocorrer erros de referência indefinida.

Na pasta `08_organizacao_arquivos`, compile e execute:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Pessoa.cpp -o pessoa
./pessoa
```
