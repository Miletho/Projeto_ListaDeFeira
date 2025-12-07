#pragma once
#include "ItemBase.h"

class Roupa : public ItemBase {
private:
    std::string tamanho;

public:
    Roupa(const std::string& nome_, double quantidade_, const std::string& tamanho_);

    void exibirInfo() const override;
    void setNome(const std::string& n) override { nome = n; }

};
