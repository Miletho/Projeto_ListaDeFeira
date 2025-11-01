#include "Doce.h"
#include <iostream>

Doce::Doce(const std::string& n, int q, bool l) : Feira(n, q), light(l) {}

void Doce::exibirInfo() const {
    std::cout << "[Doce] " << nome
              << " | Quantidade: " << quantidade
              << " | Light: " << (light ? "Sim" : "Não") << std::endl;
}

