#ifndef APP_H
#define APP_H

#include "ListaDeFeira.h"
#include "Hortalica.h"
#include "AlimentoBase.h"
#include "Acougue.h"
#include "ProdutoLimpeza.h"
#include "Doce.h"

class App {
private:
    ListaDeFeira lista;
    void menuAdicionar();

public:
    void executar();
};

#endif

