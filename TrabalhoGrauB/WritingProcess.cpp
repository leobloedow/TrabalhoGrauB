#include "WritingProcess.h"
#include <fstream>
#include <iostream>

using namespace std;

WritingProcess::WritingProcess(int pid, const string& expressao) : Processo(pid), expressao(expressao) {}

void WritingProcess::execute() {
    ofstream arquivo("computation.txt", ios::app);

    if (arquivo.is_open()) {
        arquivo << expressao << endl;
        arquivo.close();
        
        cout << "Processo " << pid << " [Gravação]: Expressão '"  << expressao << "' gravada com sucesso." << endl;
    }
    else {
        cout << "Processo " << pid << " [Gravação]: Erro ao abrir arquivo." << endl;
    }
}
