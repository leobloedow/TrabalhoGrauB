#include "ReadingProcess.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

ReadingProcess::ReadingProcess(int pid, Fila<Processo*>& processos)
    : Processo(pid), processos(processos) {}

void ReadingProcess::execute() {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Processo " << pid << " [Leitura]: Erro ao abrir arquivo de computacao: " << nomeArquivo << endl;
        return;
    }

    string line;
    int numProcessesAdded = 0;
    while (getline(arquivo, line)) {
        stringstream ss(line);
        double num1, num2;
        char op;
        
        ss >> num1 >> op >> num2;

        static int currentMaxPid = 1000;
        currentMaxPid++;
        Processo* novo = new ComputingProcess(currentMaxPid, num1, num2, op);
        processos.push(novo);
        numProcessesAdded++;
    }
    arquivo.close();

    ofstream clearFile(nomeArquivo, ios::trunc);
    clearFile.close();

    cout << "Processo " << pid << " [Leitura]: " << numProcessesAdded << " expressoes lidas e adicionadas a fila." << endl;
}
