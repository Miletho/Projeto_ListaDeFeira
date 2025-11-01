#include "ListaDeFeira.h"
#include <iostream>
#include <algorithm>

ListaDeFeira::~ListaDeFeira() {
    for (size_t i = 0; i < itens.size(); ++i)
        delete itens[i];
}

void ListaDeFeira::adicionar(Feira* item) {
    itens.push_back(item);
}

void ListaDeFeira::listar() const {
    if (itens.empty()) {
        std::cout << "Lista vazia.\n";
        return;
    }
    for (size_t i = 0; i < itens.size(); ++i)
        itens[i]->exibirInfo();
}

void ListaDeFeira::remover(const std::string& nome) {
    for (size_t i = 0; i < itens.size(); ++i) {
        if (itens[i]->getNome() == nome) {
            delete itens[i];
            itens.erase(itens.begin() + i);
            std::cout << "Item removido.\n";
            return;
        }
    }
    std::cout << "Item não encontrado.\n";
}

void ListaDeFeira::atualizar(const std::string& nome, int novaQuantidade) {
    for (size_t i = 0; i < itens.size(); ++i) {
        if (itens[i]->getNome() == nome) {
            itens[i]->setQuantidade(novaQuantidade);
            std::cout << "Quantidade atualizada.\n";
            return;
        }
    }
    std::cout << "Item não encontrado.\n";
}

