#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

Sistema::Sistema() : processos(), nextPid(1) {}

void Sistema::listarOpcoes() {
    cout << "\nSelecione a opcao desejada:" << endl;
    cout << "1 - Criar processo" << endl;
    cout << "2 - Executar proximo processo" << endl;
    cout << "3 - Executar processo por PID" << endl;
    cout << "4 - Salvar fila para arquivo" << endl;
    cout << "5 - Carregar fila de arquivo" << endl;
    cout << "6 - Sair" << endl;
    cout << "Opcao: ";
}

void Sistema::criarProcesso() {
    cout << "\nSelecione o tipo de processo:" << endl;
    cout << "1 - Processo de Calculo" << endl;
    cout << "2 - Processo de Gravacao" << endl;
    cout << "3 - Processo de Impressao" << endl;
    cout << "4 - Processo de Leitura" << endl;
    cout << "Tipo: ";
    int tipoProcesso;
    cin >> tipoProcesso;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Processo* novoProcesso = nullptr;

    switch (tipoProcesso) {
        case 1: {
            double num1, num2;
            char op;
            cout << "Digite o primeiro numero: ";
            cin >> num1;
            cout << "Digite o operador (+, -, *, /): ";
            cin >> op;
            cout << "Digite o segundo numero: ";
            cin >> num2;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            novoProcesso = new ComputingProcess(nextPid++, num1, num2, op);
            break;
        }
        case 2: {
            string expressao;
            cout << "Digite a expressao a ser gravada: ";
            getline(cin, expressao);
            novoProcesso = new WritingProcess(nextPid++, expressao);
            break;
        }
        case 3: {
            novoProcesso = new PrintingProcess(nextPid++, processos);
            break;
        }
        case 4: {
            novoProcesso = new ReadingProcess(nextPid++, processos);
            break;
        }
        default:
            return;
    }

    if (novoProcesso) {
        processos.push(novoProcesso);
        cout << "Processo " << novoProcesso->getPid() << " de tipo " << novoProcesso->getTipo() << " criado e adicionado a fila." << endl;
    }
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Processo* processToExecute = nullptr;
    Node<Processo*>* current = processos.getInicio();
    Node<Processo*>* nodeToRemove = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->data->getPid() == pidBusca) {
            processToExecute = current->data;
            nodeToRemove = current;
            found = true;
            break;
        }
        current = current->proximo;
    }

    if (found) {
        cout << "Executando processo (PID: " << processToExecute->getPid() << ", Tipo: " << processToExecute->getTipo() << ")" << endl;
        processToExecute->execute();

        if (nodeToRemove->anterior) {
            nodeToRemove->anterior->proximo = nodeToRemove->proximo;
        } else {
            processos.setInicio(nodeToRemove->proximo);
        }

        if (nodeToRemove->proximo) {
            nodeToRemove->proximo->anterior = nodeToRemove->anterior;
        } else {
            processos.setFim(nodeToRemove->anterior);
        }

        delete nodeToRemove;
        processos.setTamanho(processos.getTamanho() - 1);
        cout << "Processo removido apos execucao." << endl;

    } else {
        cout << "Processo PID: " << pidBusca << " nao encontrado!" << endl;
    }
}

void Sistema::salvarFila() {
    ofstream arquivo("Fila.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo para salvar a fila." << endl;
        return;
    }

    Node<Processo*>* current = processos.getInicio();
    while (current != nullptr) {
        Processo* p = current->data;
        arquivo << p->getPid() << "|" << p->getTipo();

        // Save specific attributes based on type
        if (p->getTipo() == "Cálculo") {
            ComputingProcess* cp = dynamic_cast<ComputingProcess*>(p);
            if (cp) {
                arquivo << "|" << cp->getNumero1() << "|" << cp->getOpMatematico() << "|" << cp->getNumero2();
            }
        } else if (p->getTipo() == "Gravação") {
            WritingProcess* wp = dynamic_cast<WritingProcess*>(p);
            if (wp) {
                arquivo << "|" << wp->getExpressao();
            }
        } // PrintingProcess and ReadingProcess don't have unique data to save beyond PID/Type
        arquivo << endl;
        current = current->proximo;
    }

    arquivo.close();
    cout << "Fila de processos salva em Fila.txt com sucesso!" << endl;
}

void Sistema::carregarFila() {
    // Clear existing processes to avoid duplicates
    while (processos.getTamanho() > 0) {
        processos.pop();
    }
    nextPid = 1;

    ifstream arquivo("Fila.txt");
    if (!arquivo.is_open()) {
        cout << "Nenhum arquivo de fila de processos encontrado ou erro ao abrir." << endl;
        return;
    }

    string line;
    while (getline(arquivo, line)) {
        stringstream ss(line);
        string segment;
        int pid;
        string tipo;

        getline(ss, segment, '|');
        pid = stoi(segment);
        getline(ss, tipo, '|');

        Processo* loadedProcess = nullptr;
        if (tipo == "Cálculo") {
            double num1, num2;
            char op;
            getline(ss, segment, '|'); num1 = stod(segment);
            getline(ss, segment, '|'); op = segment[0];
            getline(ss, segment, '|'); num2 = stod(segment);
            loadedProcess = new ComputingProcess(pid, num1, num2, op);
        } else if (tipo == "Gravação") {
            string expressao;
            getline(ss, expressao, '|');
            loadedProcess = new WritingProcess(pid, expressao);
        } else if (tipo == "Impressão") {
            loadedProcess = new PrintingProcess(pid, processos);
        } else if (tipo == "Leitura") {
            loadedProcess = new ReadingProcess(pid, processos);
        }

        if (loadedProcess) {
            processos.push(loadedProcess);
            if (pid >= nextPid) {
                nextPid = pid + 1;
            }
        }
    }
    arquivo.close();
    cout << "Fila de processos carregada de Fila.txt com sucesso!" << endl;
}
