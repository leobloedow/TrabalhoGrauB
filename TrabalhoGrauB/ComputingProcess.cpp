#include "ComputingProcess.h"
#include <iostream>

using namespace std;

void ComputingProcess::execute() {

    double resultado;

        switch (operadorMatematico) {

        case '+': resultado = numero1 + numero2; break;

        case '-': resultado = numero1 - numero2; break;

        case '*': resultado = numero1 * numero2; break;

        case '/':
            if (numero2 == 0) {
                cout << "Erro: Divisão por zero!" << endl;
                return;
            }
            resultado = numero1 / numero2;
            break;

        default:
            cout << "Operador inválido: " << operadorMatematico << endl;
            return;
        }
            cout << "Processo " << pid << " [Cálculo]: "
            << numero1 << " " << operadorMatematico << " " << numero2
            << " = " << resultado << endl;

}
    string ComputingProcess::getTipo() const {
        return "Cálculo";
}
