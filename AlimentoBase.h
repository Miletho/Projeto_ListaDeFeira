#pragma once
#include "ItemBase.h"

class AlimentoBase : public ItemBase {
public:
    AlimentoBase(const std::string& nome_, double quantidade_);

    void exibirInfo() const override;
};
