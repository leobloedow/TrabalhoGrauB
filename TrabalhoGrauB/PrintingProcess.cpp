#include "PrintingProcess.h"
#include <iostream>

using namespace std;

PrintingProcess::PrintingProcess(int pid, Fila<Processo*>& processos)
    : Processo(pid), processos(processos) { // Initialize both base and member
}

void PrintingProcess::execute() {
    cout << "\nProcesso " << pid << " [Impressão]: Lista de Processos\n";
    cout << "----------------------------------------\n";

    Node<Processo*>* atual = processos.getInicio();
    if (atual == nullptr) {
        cout << "Fila vazia.\n";
        return;
    }

    while (atual != nullptr) {
        Processo* p = atual->data;
        cout << "PID: " << p->getPid()
            << " | Tipo: " << p->getTipo() << endl;
        atual = atual->proximo;
    }
    cout << "Total: " << processos.getTamanho() << " processos\n"; // Use filaProcessos here
    cout << "----------------------------------------\n";
}
