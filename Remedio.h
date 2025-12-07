#pragma once
#include "ItemBase.h"

class Remedio : public ItemBase {
private:
    std::string uso;

public:
    Remedio(const std::string& nome_, double quantidade_, const std::string& uso_);

    void exibirInfo() const override;
};

