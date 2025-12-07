#pragma once
#include "ListaDeFeira.h"

class App {
private:
    ListaDeFeira lista;

    int lerInteiro();
    double lerDouble();
    void limparEntrada();

    void menuAdicionar();
    void menuListar();
    void menuAtualizar();
    void menuRemover();
    void abrirConfiguracoes();

public:
    App() = default;
    void executar();
};
