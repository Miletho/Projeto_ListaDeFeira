#pragma once
#include <string>

class Nome {
protected:
    std::string nome;

public:
    Nome(const std::string& nome_) : nome(nome_) {}
    virtual ~Nome() = default;

    virtual std::string getNome() const = 0;
    virtual void setNome(const std::string& n) = 0;
};
