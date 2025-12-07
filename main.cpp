#include "App.h"
#include "Configuracoes.h"
#include <iostream>

Configuracoes configGlobal;

int main() {
    configGlobal.carregar("config.txt");

    std::cout << "==============================\n";
    std::cout << " Tema: " << configGlobal.getTema() << "\n";
    std::cout << " Usuario: " << configGlobal.getNome() << "\n";
    std::cout << "==============================\n\n";

    App app;
    app.executar();

    configGlobal.salvar("config.txt");

    return 0;
}
