#include <iostream>
using namespace std;

int main() {
    cout << "LISTA (std::list):\n"
         << "  Insercao: push_front(), push_back() ou insert().\n"
         << "  Remocao: pop_front(), pop_back(), remove() ou erase().\n"
         << "  Ordem: nao obriga FIFO nem LIFO.\n"
         << "  Aplicacao: gerenciador de tarefas.\n\n"
         << "FILA (std::queue):\n"
         << "  Insercao: push() no final.\n"
         << "  Remocao: pop() no inicio.\n"
         << "  Ordem: FIFO (primeiro a entrar, primeiro a sair).\n"
         << "  Aplicacao: fila de impressao ou atendimento.\n\n"
         << "PILHA (std::stack):\n"
         << "  Insercao: push() no topo.\n"
         << "  Remocao: pop() no topo.\n"
         << "  Ordem: LIFO (ultimo a entrar, primeiro a sair).\n"
         << "  Aplicacao: desfazer acoes em um editor.\n";
    return 0;
}
