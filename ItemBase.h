#pragma once

#include <string>
#include "IExibivel.h"
#include "Nome.h"
#include <iostream>

class ItemBase : public IExibivel, public Nome {

protected:
    double quantidade;

public:
    ItemBase(const std::string& nome_, double quantidade_)
        : Nome(nome_), quantidade(quantidade_) {}

    virtual ~ItemBase() = default;

    std::string getNome() const override {
        return nome;
    }

    void setNome(const std::string& n) override {
        nome = n;
    }

    double getQuantidade() const { return quantidade; }
    void setQuantidade(double q) { quantidade = q; }

    virtual void exibirInfo() const override = 0;
};
