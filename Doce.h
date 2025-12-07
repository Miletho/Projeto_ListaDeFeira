#pragma once
#include "ItemBase.h"

class Doce : public ItemBase {
private:
    bool light;

public:
    Doce(const std::string& nome_, double quantidade_, bool light_);

    void exibirInfo() const override;
};
