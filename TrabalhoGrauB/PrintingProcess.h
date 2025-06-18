#pragma once
#include "Processo.h"
#include "Fila.h"
#include <iostream>

using namespace std;

class PrintingProcess : public Processo {
   
private:
        Fila<Processo*>& filaProcessos;

public:

    PrintingProcess(int pid, Fila<Processo*>& filaProcessos);

    void execute();

    string getTipo() const { return "Impressão"; }

};
