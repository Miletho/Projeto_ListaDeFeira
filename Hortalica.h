#pragma once
#include "ItemBase.h"

class Hortalica : public ItemBase {
private:
    bool organica;

public:
    Hortalica(const std::string& nome_, double quantidade_, bool organica_);

    void exibirInfo() const override;
};
