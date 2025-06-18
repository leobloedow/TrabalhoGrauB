#pragma once
#include "Processo.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class WritingProcess : public Processo {

private:

    string expressao;
    const string nomeArquivo = "computation.txt";

public:
    
    WritingProcess(int pid, const string& expressao);

    void execute() override;
    
    string getTipo() override { return "Gravação"; }

    string getExpressao() const { return expressao; }
};
