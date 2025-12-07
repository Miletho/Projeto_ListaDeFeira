#pragma once
#include "ItemBase.h"

class Higiene : public ItemBase {
private:
    std::string uso;

public:
    Higiene(const std::string& nome_, double quantidade_, const std::string& uso_);

    void exibirInfo() const override;
};
