#include "Roupa.h"
#include <iostream>

Roupa::Roupa(const std::string& nome_, double quantidade_, const std::string& tamanho_)
    : ItemBase(nome_, quantidade_), tamanho(tamanho_) {}

void Roupa::exibirInfo() const {
    std::cout << "[Roupa] " << nome
              << " | Quantidade: " << quantidade
              << " | Tamanho: " << tamanho
              << std::endl;
}

