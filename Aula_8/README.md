# Programação II — Aula 8: exercícios resolvidos

Resoluções dos 12 exercícios da lista da Aula 8 em C++17. Cada arquivo `.cpp` contém uma solução independente, com testes em `main()` e comentários explicativos.

## Arquivos e explicações

| Exercício | Arquivo | Resposta |
|---|---|---|
| 1 | `01_matriz_dinamica.cpp` | Matriz no heap com `int**`; cópia profunda aloca linhas independentes, destrutor libera cada linha e o vetor de ponteiros. |
| 2 | `02_construtores_retangulo.cpp` | Construtores padrão (1×1), parametrizado e de quadrado; área e perímetro. |
| 3 | `03_produto_lista_inicializacao.cpp` | `const int codigo` deve ser inicializado na lista do construtor; atribuição no corpo não é válida para `const`. |
| 4 | `04_copia_rasa_profunda.cpp` | Cópia rasa duplica endereço e faz os objetos observarem a mesma memória; pode causar alteração compartilhada ou double-free se ambos forem donos. Cópia profunda cria memória independente. |
| 5 | `05_arquivo_texto_raii.cpp` | `ArquivoTexto` abre o arquivo no construtor e fecha no destrutor. RAII vincula a vida do recurso ao escopo do objeto. Produz `saida_aula8.txt`. |
| 6 | `06_ordem_construcao_destruicao.cpp` | Ordem de construção: A, B, C; destruição: C, B, A, ao sair de cada escopo. |
| 7 | `07_sobrecarga_calcular_area.cpp` | Quadrado, retângulo e triângulo. `TrianguloTag` distingue o triângulo porque `calcularArea(double,double)` não pode ser redefinida apenas mudando nomes de parâmetros; tipo de retorno isolado tampouco cria sobrecarga. |
| 8 | `08_operadores_contador.cpp` | Prefixado `operator++()` retorna referência ao valor atualizado; pós-fixado `operator++(int)` retorna cópia do valor anterior. |
| 9 | `09_operadores_vetor3d.cpp` | Soma componente a componente e produto escalar `x1*x2 + y1*y2 + z1*z2`. |
| 10 | `10_regras_sobrecarga.cpp` | (a) operador novo: não; (b) mudar precedência: não; (c) `+` entre objetos próprios: sim; (d) redefinir `int + int`: não; (e) `+` para excluir registros: sintaxe surpreendente, desaconselhada. |
| 11 | `11_string_segura_default_delete.cpp` | `unique_ptr<char[]>` mantém posse exclusiva. Movimento marcado `= default` e cópia `= delete`; tentativas de cópia estão comentadas porque não compilariam. |
| 12 | `12_buffer_dinamico.cpp` | Buffer com cópia profunda, destrutor, construtor/atribuição por movimento e soma por `operator+`; tamanhos distintos geram exceção. |

## Como executar no Ubuntu

Na pasta `Aula_8`, compile por exemplo:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic 01_matriz_dinamica.cpp -o programa
./programa
```

Troque o `.cpp` pelo exercício desejado. Para compilar e executar todos, use `bash testar_tudo.sh`.

Para investigar problemas de memória com o AddressSanitizer:

```bash
g++ -std=c++17 -g -fsanitize=address,undefined -fno-omit-frame-pointer 12_buffer_dinamico.cpp -o buffer
./buffer
```

## Observações

- No exercício 4, a demonstração de cópia rasa evita deliberadamente dois proprietários realizando `delete` sobre o mesmo ponteiro, o que seria comportamento indefinido.
- No exercício 1, a atribuição de cópia emprega `copy-and-swap`, evitando deixar o objeto com estado parcial se a cópia falhar.
- No exercício 5, o próprio `ofstream` também fecha seu recurso automaticamente quando destruído.
- No exercício 12, cópia aloca outro vetor e movimento transfere a propriedade do vetor, tornando a origem vazia.
- Os 12 programas foram compilados com `-Werror` e executados com sucesso.