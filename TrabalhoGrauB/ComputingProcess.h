#pragma once
#include "Processo.h"
#include <string>

using namespace std;

class ComputingProcess : public Processo {

    private:

        double numero1;
        double numero2;
        char operadorMatematico;

    public:
    
        ComputingProcess(int pid, double n1, double n2, char op)
            : Processo(pid), numero1(n1), numero2(n2), operadorMatematico(op) {
        }

        void execute();

        string getTipo();

        double getNumero1() const { return numero1; }
        double getNumero2() const { return numero2; }
        char getOpMatematico() const { return operadorMatematico; }
};
