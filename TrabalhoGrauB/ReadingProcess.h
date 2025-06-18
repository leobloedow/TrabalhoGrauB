#pragma once
#include "Processo.h"
#include "Fila.h"
#include "ComputingProcess.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class ReadingProcess : public Processo {
private:
    Fila<Processo*>& processos;
    const string nomeArquivo = "computation.txt";

public:
    ReadingProcess(int pid, Fila<Processo*>& processos);

    void execute();

    string getTipo() { return "Leitura"; }
};
