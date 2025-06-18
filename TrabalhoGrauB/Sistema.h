#pragma once
#include "Fila.h"
#include "Processo.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "PrintingProcess.h"

class Sistema {
public:
    Sistema();
    void listarOpcoes();
    void criarProcesso();
    void executarProximo();
    void executarProcesso();
    void salvarFila();
    void carregarFila();
private:
    Fila<Processo*> processos;
};

