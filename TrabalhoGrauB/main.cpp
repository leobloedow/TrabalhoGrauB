#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    Sistema s = Sistema();
    
    while(true) {
        s.listarOpcoes();
        int opcao = 0;
        cin >> opcao;
        switch (opcao) {
            case 1:
                s.criarProcesso();
                continue;
            case 2:
                s.executarProximo();
                continue;
            case 3:
                s.executarProcesso();
                continue;
            case 4:
                s.salvarFila();
                continue;
            case 5:
                s.carregarFila();
                continue;
            case 6:
                return 0;
            default:
                continue;
        }
    }
}
