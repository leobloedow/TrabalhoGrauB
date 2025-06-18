#pragma once
#include <string>

class Processo {
public:
    Processo(int id);
    virtual void execute() = 0;
    virtual std::string getTipo() = 0;
    int getPid();
protected:
    int pid;
};
