#ifndef APP_H
#define APP_H

#include "ListaDeFeira.h"

class App {
private:
    ListaDeFeira lista;

public:
    App();
    void menuAdicionar();
    void executar();
};

#endif
