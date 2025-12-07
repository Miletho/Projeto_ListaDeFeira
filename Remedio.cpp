#include "Remedio.h"
#include <iostream>

Remedio::Remedio(const std::string& nome_, double quantidade_, const std::string& uso_)
    : ItemBase(nome_, quantidade_), uso(uso_) {}

void Remedio::exibirInfo() const {
    std::cout << "[Remedio] " << nome
              << " | Quantidade: " << quantidade
              << " | Uso: " << uso
              << std::endl;
}
