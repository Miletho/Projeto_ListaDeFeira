#include "AlimentoBase.h"
#include <iostream>

AlimentoBase::AlimentoBase(const std::string& n, int q) : ItemBase(n, q) {}

void AlimentoBase::exibirInfo() const {
    std::cout << "[Alimento Base] " << nome
              << " | Quantidade: " << quantidade << std::endl;
}


