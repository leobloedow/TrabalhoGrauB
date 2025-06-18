#include "Sistema.h"
#include <iostream>

using namespace std;

Sistema::Sistema() : processos() {}

void Sistema::listarOpcoes() {
    cout << "Selecione a opcao desejada:" << endl;
    cout << "1 - Criar processo" << endl;
    cout << "2 - Executar proximo processo" << endl;
    cout << "3 - Executar processo por PID" << endl;
    cout << "4 - Salvar fila para arquivo" << endl;
    cout << "5 - Carregar fila de arquivo" << endl;
    cout << "6 - Sair" << endl;
}

void Sistema::criarProcesso() {
    // This function will need to create concrete Processo subclasses (e.g., new ComputingProcess(...))
    // and then call processos.push(new_process_pointer);
}

void Sistema::executarProximo() {
    if (processos.getTamanho() == 0) {
        cout << "Fila de processos vazia!" << endl;
        return;
    }
    Processo* p = processos.getInicio()->data;
    cout << "Executando o proximo processo - PID: " << p->getPid() << ", Tipo: " << p->getTipo() << endl;
    p->execute();
    processos.pop();
}

void Sistema::executarProcesso() {
    cout << "Digite o PID do processo a ser executado: ";
    int pidBusca;
    cin >> pidBusca;

    Processo* processToExecute = nullptr;
    Node<Processo*>* current = processos.getInicio();
    Node<Processo*>* nodeToRemove = nullptr;

    while (current != nullptr) {
        if (current->data->getPid() == pidBusca) {
            processToExecute = current->data;
            nodeToRemove = current;
            break;
        }
        current = current->proximo;
    }

    if (processToExecute != nullptr) {
        cout << "Executando processo (PID: " << processToExecute->getPid() << ", Tipo: " << processToExecute->getTipo() << ")" << endl;
        processToExecute->execute();

        if (nodeToRemove->anterior) {
            nodeToRemove->anterior->proximo = nodeToRemove->proximo;
        } else {
            processos.setInicio(nodeToRemove->proximo); // Fila needs a setInicio
        }

        if (nodeToRemove->proximo) {
            nodeToRemove->proximo->anterior = nodeToRemove->anterior;
        } else {
            processos.setFim(nodeToRemove->anterior); // Fila needs a setFim
        }

        processos.setTamanho(processos.getTamanho() - 1); // Fila needs a setTamanho or a way to decrement
        cout << "Processo removido apos execucao." << endl;

    } else {
        cout << "Processo PID:  " << pidBusca << " nao encontrado!" << endl;
    }
}


void Sistema::salvarFila() {
    
}

void Sistema::carregarFila() {
    
}
