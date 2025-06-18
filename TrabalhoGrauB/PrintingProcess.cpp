#include "PrintingProcess.h"
#include <iostream>

using namespace std;

void PrintingProcess::execute() {
    cout << "\nProcesso " << pid << " [Impressão]: Lista de Processos\n";
    cout << "----------------------------------------\n";

    Node<Processo>* atual = processos.getInicio();
    if (atual == nullptr) {
        cout << "Fila vazia.\n";
        return;
    }

    while (atual != nullptr) {
        Processo& p = atual->data;
        cout << "PID: " << p.getPid()
            << " | Tipo: " << p.getTipo() << endl;
        atual = atual->proximo;
    }
    cout << "Total: " << processos.getTamanho() << " processos\n";
    cout << "----------------------------------------\n";
}
