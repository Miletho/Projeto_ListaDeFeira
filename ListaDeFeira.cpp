#include "ListaDeFeira.h"
#include <iostream>
#include <algorithm>

void ListaDeFeira::adicionar(std::shared_ptr<Feira> item) {
    itens.push_back(item);
}

void ListaDeFeira::listar() const {
    if (itens.empty()) {
        std::cout << "Lista vazia.\n";
        return;
    }
    for (auto& i : itens)
        i->exibirInfo();
}

void ListaDeFeira::remover(const std::string& nome) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if ((*it)->getNome() == nome) {
            itens.erase(it);
            std::cout << "Item removido.\n";
            return;
        }
    }
    std::cout << "Item não encontrado.\n";
}

void ListaDeFeira::atualizar(const std::string& nome, int novaQuantidade) {
    for (auto& i : itens) {
        if (i->getNome() == nome) {
            i->setQuantidade(novaQuantidade);
            std::cout << "Quantidade atualizada.\n";
            return;
        }
    }
    std::cout << "Item não encontrado.\n";
}
