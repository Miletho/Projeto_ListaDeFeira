#pragma once
#include "ItemBase.h"

class Acougue : public ItemBase {
private:
    std::string corte;

public:
    Acougue(const std::string& nome_, double quantidade_, const std::string& corte_);

    void exibirInfo() const override;

};
