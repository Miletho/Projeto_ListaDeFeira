#include "ListaDeFeira.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>

void ListaDeFeira::adicionar(std::shared_ptr<Feira> f) {
    if (f->getQuantidade() <= 0)
        throw std::invalid_argument("Quantidade inválida! Deve ser maior que zero.");
    itens.push_back(f);
    std::cout << "Item adicionado com sucesso!\n";
}

void ListaDeFeira::listar() const {
    if (itens.empty()) {
        std::cout << "A lista de feira está vazia.\n";
        return;
    }
    for (const auto& f : itens)
        f->exibirInfo();
}

void ListaDeFeira::atualizar(const std::string& nome) {
    for (auto& f : itens) {
        if (f->getNome() == nome) {
            int novaQtd;
            std::cout << "Nova quantidade: ";
            if (!(std::cin >> novaQtd))
                throw std::invalid_argument("Entrada inválida!");
            if (novaQtd <= 0)
                throw std::invalid_argument("Quantidade deve ser maior que zero!");
            f->setQuantidade(novaQtd);
            std::cout << "Item atualizado!\n";
            return;
        }
    }
    throw std::logic_error("Item não encontrado para atualização!");
}

void ListaDeFeira::remover(const std::string& nome) {
    auto it = std::remove_if(itens.begin(), itens.end(),
                             [&](const std::shared_ptr<Feira>& f) {
                                 return f->getNome() == nome;
                             });
    if (it != itens.end()) {
        itens.erase(it, itens.end());
        std::cout << "Item removido com sucesso!\n";
    } else {
        throw std::logic_error("Item não encontrado para remoção!");
    }
}
