#include "Acougue.h"
#include <iostream>

Acougue::Acougue(const std::string& n, int q, const std::string& c) : ItemBase(n, q), corte(c) {}

void Acougue::exibirInfo() const {
    std::cout << "[Açougue] " << nome
              << " | Quantidade: " << quantidade
              << " | Corte: " << corte << std::endl;
}


