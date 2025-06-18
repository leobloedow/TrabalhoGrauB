#pragma once
#include "Processo.h"
#include "Fila.h"
#include <iostream>
#include <string>

using namespace std;

class PrintingProcess : public Processo {
   
private:
    Fila<Processo*>& processos;

public:
    PrintingProcess(int pid, Fila<Processo*>& processos);

    void execute();

    string getTipo() { return "Impressão"; }

};
