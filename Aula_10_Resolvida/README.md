# Lista de Atividades - Aula 10 (Programacao II)

As oito questoes do PDF foram resolvidas em **C++17**. Cada arquivo `NN_*.cpp` e um programa independente, com seu proprio `main()`. Os testes usam valores ilustrativos; onde o enunciado nao pede entrada do usuario, os dados sao definidos no codigo.

## Arquivos

| Questao | Arquivo | Conteudo |
|---|---|---|
| 1 | `01_heranca.cpp` | Classe `Veiculo`, `Carro` e atributos herdados |
| 2 | `02_funcoes_virtuais.cpp` | `emitirSom()`, `virtual`, `override` e `Motocicleta` |
| 3 | `03_visibilidade.cpp` | `public`, `protected`, `private` e `Gerente` |
| 4 | `04_polimorfismo.cpp` | Ponteiros para a classe base, despacho virtual e nao virtual |
| 5 | `05_classe_abstrata.cpp` | `FormaGeometrica`, `Retangulo`, `Circulo`, areas e perimetros |
| 6 | `06_destrutor_virtual.cpp` | `new`, destrutor virtual e `delete[]` de um recurso adicional |
| 7 | `07_diamante.cpp` | Heranca multipla, ambiguidade e heranca virtual |
| 8 | `08_notificacoes.cpp` | `Notificacao` abstrata e classes `Email`, `SMS`, `NotificacaoPush` |

O arquivo `Enunciado_Aula_10.pdf` e uma copia da lista original. O script `testar_tudo.sh` compila e testa os 8 programas e as variantes dos exercicios 4 e 7.

## Como compilar e executar (Linux / Ubuntu)

Dentro desta pasta, para executar uma questao especifica:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic 01_heranca.cpp -o exercicio1
./exercicio1
```

Para executar todos os testes:

```bash
bash testar_tudo.sh
```

Os binarios temporarios dos testes ficam em uma pasta temporaria e sao removidos no final.

## Respostas e explicacoes

### 1. Heranca

`Carro : public Veiculo` estabelece uma relacao **e um**: `Carro` e uma especializacao de `Veiculo`. Como `marca` e publica na base e a heranca e publica, `carro.marca` pode ser acessado em `main`. `numeroPortas` e o campo especifico da derivada.

### 2. Funcoes virtuais

`virtual` na classe base permite que chamadas a `emitirSom()` feitas por `Veiculo*` ou `Veiculo&` executem a implementacao correspondente ao tipo real do objeto. `override` verifica na compilacao que o metodo da derivada realmente sobrescreve um metodo virtual da base. A base exibe um ruido generico; o carro emite a buzina e a motocicleta tem seu som proprio.

### 3. Visibilidade e tipo de heranca

- `public`: pode ser acessado pela propria classe, pela derivada e pelo programa principal.
- `protected`: pode ser acessado pela propria classe e por metodos da derivada, mas **nao** diretamente em `main`.
- `private`: so pode ser acessado pelos metodos (e amigos, se houver) da classe que o declarou; nem uma derivada pode acessar diretamente. Um metodo publico da base, como `mostrarDocumento()`, pode expor o valor de maneira controlada.

Na **heranca publica** (`class Gerente : public Funcionario`), os atributos publicos herdados permanecem publicos, e os protegidos permanecem protegidos. Na **heranca protegida**, membros publicos e protegidos acessiveis da base tornam-se protegidos na derivada. Na **heranca privada**, tornam-se privados na derivada. O atributo `documento` continua inacessivel diretamente a `Gerente` em todos os casos. As linhas que provocariam erro de compilacao estao comentadas no codigo; podem ser descomentadas individualmente para observar as mensagens do compilador.

### 4. Polimorfismo dinamico versus vinculacao estatica

O programa guarda `&veiculo`, `&carro` e `&moto` em `vector<Veiculo*>` e chama `emitirSom()` pelo ponteiro da base.

**Com `virtual` (padrao):**

```text
COM virtual: vinculacao DINAMICA
Veiculo: ruido generico do motor.
Carro: bi-bi!
Motocicleta: vruuum!
```

**Sem `virtual`:**

```bash
g++ -std=c++17 -DSEM_VIRTUAL 04_polimorfismo.cpp -o exercicio4_sem_virtual
./exercicio4_sem_virtual
```

```text
SEM virtual: vinculacao ESTATICA
Veiculo: ruido generico do motor.
Veiculo: ruido generico do motor.
Veiculo: ruido generico do motor.
```

Na **vinculacao dinamica**, escolhe-se a funcao a partir do tipo real do objeto em tempo de execucao. Na **vinculacao estatica**, escolhe-se pelo tipo estatico da expressao (`Veiculo*`) na compilacao. O marcador `override` precisa ser removido quando a funcao deixa de ser virtual; o codigo o faz automaticamente ao ativar `SEM_VIRTUAL`.

### 5. Classe abstrata

Uma funcao `virtual ... = 0` e uma funcao virtual pura. `FormaGeometrica` tem funcoes virtuais puras para area e perimetro (alem de `nome()` para facilitar a exibicao), portanto **nao pode ser instanciada** diretamente. Cada classe concreta implementa os contratos. O programa usa `vector<unique_ptr<FormaGeometrica>>`, uma colecao de ponteiros para a base, e demonstra despacho dinamico. `unique_ptr` evita vazamentos de memoria.

Formulas: retangulo `A = largura * altura` e `P = 2 * (largura + altura)`; circulo `A = pi * raio^2` e `P = 2 * pi * raio`.

### 6. Destrutor virtual e memoria

O construtor de `RecursoArquivo` aloca um `char[128]` com `new[]`. Ao executar `delete recurso;` onde `recurso` e `Recurso*`, o destrutor **virtual** da base garante a chamada de `~RecursoArquivo()` e depois `~Recurso()`. A derivada libera o buffer com `delete[]`.

Se a classe base tivesse destrutor nao virtual e o objeto derivado fosse destruido por um `Recurso*`, o comportamento seria **indefinido** em C++; o destrutor derivado poderia nao executar, deixando o recurso alocado e causando vazamento ou outros problemas. Nao execute essa variante incorreta, pois seu comportamento nao e confiavel.

### 7. Problema do diamante

Sem heranca virtual, `Multifuncional` possui **duas subinstancias** de `Dispositivo`: uma por `Impressora` e outra por `Scanner`. `aparelho.identificador` e ambiguo, pois existem dois membros com o mesmo nome.

Para observar a duplicacao:

```bash
g++ -std=c++17 -DSEM_HERANCA_VIRTUAL 07_diamante.cpp -o exercicio7_sem_virtual
./exercicio7_sem_virtual
```

A saida identifica duas bases distintas (`false`, com IDs 101 e 202). Na versao padrao, `Impressora` e `Scanner` herdam `virtual public Dispositivo`, compartilhando **uma unica subinstancia** da base. Assim, o teste de identidade retorna `true`, e `aparelho.identificador` pode ser acessado sem ambiguidade.

### 8. Sistema de notificacoes

**Heranca:** `Email`, `SMS` e `NotificacaoPush` derivam de `Notificacao`. **Abstracao:** o contrato `enviar()` e declarado como virtual puro. **Polimorfismo dinamico:** uma colecao de `unique_ptr<Notificacao>` chama `enviar()` sem testar o tipo concreto com `if`/`switch`. **Aberto/Fechado (OCP):** e possivel acrescentar uma nova classe de notificacao implementando `enviar()` sem alterar o laco que processa notificacoes existentes. Para incluir instancias da nova classe, basta registra-las na colecao.

Os envios sao **simulados em console**; nao ha comunicacao real com servidores de email, SMS ou push.

## Observacoes

- Cada arquivo deve ser compilado **separadamente**, pois todos possuem `main()`.
- Os comentarios que mostram trechos invalidos dos exercicios 3, 5 e 7 foram mantidos comentados intencionalmente, para nao impedir a compilacao.
- `unique_ptr` e `make_unique` exigem pelo menos **C++14**; os exemplos sao compilados com **C++17**.
