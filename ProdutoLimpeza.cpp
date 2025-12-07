#include "ProdutoLimpeza.h"
#include <iostream>

ProdutoLimpeza::ProdutoLimpeza(const std::string& n, int q, const std::string& u) : ItemBase(n, q), uso(u) {}

void ProdutoLimpeza::exibirInfo() const {
    std::cout << "[Produto de Limpeza] " << nome
              << " | Quantidade: " << quantidade
              << " | Uso: " << uso << std::endl;
}


