# Programacao II - Lista de Atividades da Aula 6

Solucao dos **12 exercicios** propostos na lista da professora Taina Isabela, com um programa independente por exercicio (C++17). Os codigos sao interativos quando o enunciado solicita insercao ou manipulacao de dados.

## Como executar no Ubuntu

Na pasta `Aula_6`, compile o exercicio desejado, por exemplo:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic 03_lista_de_tarefas.cpp -o tarefas
./tarefas
```

Para compilar qualquer um, substitua o nome do arquivo `.cpp` e o nome do executavel. Os programas nao dependem de bibliotecas externas.

## Respostas e explicacoes

| Questao | Arquivo | Explicacao |
| --- | --- | --- |
| 1 | `01_ponteiro_inteligente.cpp` | `make_unique<int>(42)` cria um inteiro sob posse de `unique_ptr`; ao sair do escopo, o destrutor libera a memoria automaticamente, dispensando `delete`. |
| 2 | `02_comparacao_smart_pointers.cpp` | `unique_ptr` tem posse exclusiva e pode transferi-la com `move`; `shared_ptr` compartilha posse e `use_count()` informa quantos donos existem; `weak_ptr` observa sem manter o objeto vivo e `lock()` so retorna um `shared_ptr` valido se o objeto ainda existir. |
| 3 | `03_lista_de_tarefas.cpp` | `list<string>` insere no inicio/fim, remove todas as correspondencias exatas com `remove()`, percorre com `for` e conta com `size()`. |
| 4 | `04_lista_inteiros.cpp` | `list<int>` usa `push_back()`, `pop_front()`, `pop_back()` e `remove()`. `empty()` evita remocao invalida. |
| 5 | `05_fila_documentos.cpp` | `queue<string>` processa com `front()` e `pop()` na ordem de chegada: FIFO. |
| 6 | `06_fila_atendimento.cpp` | Nomes entram com `push()` e saem com `front()`/`pop()`; `size()` mostra a quantidade aguardando. |
| 7 | `07_editor_pilha.cpp` | `stack<string>` empilha com `push()`, consulta com `top()` e desfaz com `pop()`: LIFO. |
| 8 | `08_inverter_frase_pilha.cpp` | Cada palavra lida vai para a pilha; a retirada com `top()` e `pop()` inverte a ordem das palavras, pois a ultima entrada e a primeira saida. |
| 9 | `09_pilha_manual.cpp` | Array de 5 elementos mais indice `topo` implementa uma pilha sem `std::stack`, com verificacoes de vazia e cheia. |
| 10 | `10_fila_manual.cpp` | Array circular com `inicio`, `fim` e `quantidade` implementa FIFO sem `std::queue`; o primeiro valor inserido e o primeiro removido. |
| 11 | `11_lista_encadeada.cpp` | Cada no contem `valor` e `No* proximo`; sao criados cinco nos, percorridos por ponteiro e liberados um a um com `delete`. |
| 12 | `12_comparacao_estruturas.cpp` | Um programa imprime as operacoes, a regra de acesso e uma aplicacao de cada estrutura; lista nao obriga FIFO/LIFO, fila usa FIFO e pilha usa LIFO. |

## Exemplos de ordem

- **FIFO**: entram Ana, Bruno e Carla; sao atendidos Ana, Bruno e Carla.
- **LIFO**: empilha Ana, Bruno e Carla; desempilha Carla, Bruno e Ana.
- **Lista**: e possivel incluir e remover elementos nas extremidades e, conforme a operacao, em outras posicoes.

**Observacoes:** arquivos 9 e 10 usam arrays estaticos de capacidade 5 e informam quando a estrutura esta cheia. No exercicio 8 sao invertidas as **palavras**, nao os caracteres de cada palavra. O exercicio 11 utiliza `new`/`delete` de proposito, como solicitado.
