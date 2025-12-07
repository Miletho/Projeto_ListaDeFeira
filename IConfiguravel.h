#pragma once
#include <string>

class IConfiguravel {
public:
    virtual void salvar(const std::string& caminho) const = 0;
    virtual void carregar(const std::string& caminho) = 0;
    virtual ~IConfiguravel() = default;
};
