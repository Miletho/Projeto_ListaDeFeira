#include "ListaDeFeira.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>

<<<<<<< HEAD
void ListaDeFeira::adicionar(std::shared_ptr<Feira> item) {
    itens.push_back(item);
=======
void ListaDeFeira::adicionar(std::shared_ptr<Feira> f) {
    if (f->getQuantidade() <= 0)
        throw std::invalid_argument("Quantidade inválida! Deve ser maior que zero.");
    itens.push_back(f);
    std::cout << "Item adicionado com sucesso!\n";
>>>>>>> 2bdeb6f94528a5285883307e8200555d788fa00a
}

void ListaDeFeira::listar() const {
    if (itens.empty()) {
        std::cout << "A lista de feira está vazia.\n";
        return;
    }
<<<<<<< HEAD
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
=======
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
>>>>>>> 2bdeb6f94528a5285883307e8200555d788fa00a
