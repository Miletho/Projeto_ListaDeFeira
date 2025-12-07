#pragma once
#include "ItemBase.h"

class ProdutoLimpeza : public ItemBase {
private:
    std::string uso;

public:
    ProdutoLimpeza(const std::string& nome_, double quantidade_, const std::string& uso_);

    void exibirInfo() const override;
};
