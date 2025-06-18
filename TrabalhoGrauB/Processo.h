#pragma once

class Processo {
public:
    void execute();
    int getPid();
protected:
    int pid;
};
