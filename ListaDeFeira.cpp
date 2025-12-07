#include "ListaDeFeira.h"
#include "Excecoes.h"
#include <iostream>
#include <algorithm>

bool ListaDeFeira::nomeExiste(const std::string& nome) const {
    for (const auto& it : itens) {
        if (it->getNome() == nome) return true;
    }
    return false;
}

bool ListaDeFeira::adicionarItem(const std::shared_ptr<ItemBase>& item) {
    if (item == nullptr)
        throw ErroItemInvalido("Item nulo.");

    if (nomeExiste(item->getNome()))
        throw ErroItemDuplicado(item->getNome());

    itens.push_back(item);
    return true;
}

bool ListaDeFeira::removerItem(const std::string& nome) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if ((*it)->getNome() == nome) {
            itens.erase(it);
            return true;
        }
    }
    throw ErroItemNaoEncontrado(nome);
}

bool ListaDeFeira::atualizarQuantidade(const std::string& nome, double novaQuantidade) {
    if (novaQuantidade <= 0)
        throw ErroItemInvalido("Quantidade deve ser maior que zero.");

    for (auto& it : itens) {
        if (it->getNome() == nome) {
            it->setQuantidade(novaQuantidade);
            return true;
        }
    }
    throw ErroItemNaoEncontrado(nome);
}

void ListaDeFeira::listarItens() const {
    if (itens.empty()) {
        std::cout << "Lista vazia.\n";
        return;
    }
    std::cout << "\n--- Lista de Feira ---\n";
    for (const auto& it : itens) {
        it->exibirInfo();
    }
}
