#include "Hortalica.h"
#include <iostream>

Hortalica::Hortalica(const std::string& n, int q, bool o) : Feira(n, q), organica(o) {}

void Hortalica::exibirInfo() const {
    std::cout << "[Hortaliça] " << nome
              << " | Quantidade: " << quantidade
              << " | Orgânica: " << (organica ? "Sim" : "Não") << std::endl;
}

