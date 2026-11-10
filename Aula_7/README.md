# Programação II — Lista de Atividades da Aula 7

Resoluções dos **11 exercícios** da professora Tainá Isabela. Os exemplos usam C++17, classes, construtores, encapsulamento, setters/getters, organização em arquivos e linker.

## Arquivos e respostas

| Exercício | Arquivo(s) | Resposta resumida |
|---|---|---|
| 1. Classe Gato | `01_classe_gato.cpp` | Atributos `nome`, `idade` e `peso` privados; construtor e getters. `setPeso` só aceita valores positivos. |
| 2. Conta bancária | `02_conta_bancaria.cpp` | Saldo privado começa em zero; `depositar` rejeita valores não positivos; `sacar` rejeita saques não positivos ou superiores ao saldo. |
| 3. Termômetro | `03_termometro.cpp` | Temperatura começa em 25 °C, não aceita valores inferiores a −273,15 °C e calcula Fahrenheit com `C * 9.0 / 5.0 + 32.0`. |
| 4. Livros | `04_classe_livro.cpp` | Três objetos `Livro` com construtor, getters e setters. Número de páginas precisa ser positivo. |
| 5. Produto | `05_produto_encapsulamento.cpp` | Código, descrição e preço privados. `setPreco` só permite preço positivo; tentativa de acesso direto aparece comentada para não impedir compilação. |
| 6. Ponto | `06_construtores_ponto.cpp` | Sobrecarga: `Ponto()` inicializa `(0, 0)` e `Ponto(x, y)` recebe coordenadas. |
| 7. Retângulo | `07_retangulo.cpp` | Dimensões privadas, validação positiva e métodos para área e perímetro. Compara dois objetos. |
| 8. Organização | `08_organizacao_arquivos/Pessoa.h`, `Pessoa.cpp` e `main.cpp` | Separa interface, implementação e uso; `Pessoa.h` possui *include guard*. |
| 9. Linker | `09_compilacao_linker.md` | Explica cabeçalho, compilação e ligação e mostra o comando `g++` correto. |
| 10. Cadastro | `10_cadastro_pessoas.cpp` | Cadastro de várias pessoas usando `vector<Pessoa>`, getters e setter que rejeita idades negativas. |
| 11. Encapsulamento | `11_revisao_encapsulamento.cpp` | Contrasta atributos públicos com atributos privados e validação de notas de 0 a 10. |

## Como compilar no Ubuntu

Na pasta `Aula_7`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic 01_classe_gato.cpp -o gato
./gato
```

Substitua o arquivo `.cpp` para executar outro exercício.

**Exceção — exercício 8:** como a classe está dividida em dois arquivos de código, compile ambos:

```bash
cd 08_organizacao_arquivos
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Pessoa.cpp -o pessoa
./pessoa
```

## Respostas conceituais

### 5. Por que não acessar atributos privados diretamente?

Com `private`, expressões como `produto.preco = -100;` não compilam em código externo à classe. O único caminho público de alteração é `setPreco`, que recusa entradas inválidas. Nos exemplos, linhas de acesso direto estão comentadas **intencionalmente**.

### 9. Cabeçalho, compilação e linker

- `Pessoa.h`: descreve a interface da classe, para que outros arquivos saibam quais construtores e métodos existem.
- `main.cpp` inclui o cabeçalho para reconhecer a classe `Pessoa` antes de instanciá-la.
- `Pessoa.cpp`: define as funções da classe, com `Pessoa::`.
- **Linker**: reúne os arquivos-objeto e resolve referências entre eles, gerando o executável.
- Comando: `g++ main.cpp Pessoa.cpp -o pessoa` (na pasta que contém os dois `.cpp`).

### 11. Como o encapsulamento protege a integridade dos dados?

Na versão com atributos públicos, é possível atribuir uma nota igual a 15, mesmo se a escala permitida for de 0 a 10. Com atributos privados, o método `setNota` impede a atualização inválida e mantém o estado do objeto consistente. Getters fornecem leitura sem dar acesso de escrita direta.

## Observação sobre valores inválidos nos construtores

Alguns exemplos inicializam atributos com um valor-padrão válido antes de chamar o setter no construtor. Assim, uma entrada inválida não deixa o objeto com um valor proibido. Em um projeto maior, também seria possível lançar exceções para rejeitar completamente a criação.
