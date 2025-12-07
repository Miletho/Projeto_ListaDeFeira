#pragma once

#include <vector>
#include <memory>
#include <string>
#include "ItemBase.h"

class ListaDeFeira {
private:
    std::vector<std::shared_ptr<ItemBase>> itens;

public:
    ListaDeFeira() = default;

    bool nomeExiste(const std::string& nome) const;

    bool adicionarItem(const std::shared_ptr<ItemBase>& item);
    bool removerItem(const std::string& nome);
    bool atualizarQuantidade(const std::string& nome, double novaQuantidade);
    void listarItens() const;
};
