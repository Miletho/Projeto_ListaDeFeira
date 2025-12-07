#include "Higiene.h"
#include <iostream>

Higiene::Higiene(const std::string& nome_, double quantidade_, const std::string& uso_)
    : ItemBase(nome_, quantidade_), uso(uso_) {}

void Higiene::exibirInfo() const {
    std::cout << "[Higiene] " << nome
              << " | Quantidade: " << quantidade
              << " | Uso: " << uso
              << std::endl;
}
