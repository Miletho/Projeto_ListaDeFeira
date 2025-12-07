#pragma once
#include <string>
#include "IConfiguravel.h"

class Configuracoes : public IConfiguravel {
private:
    std::string nomeUsuario;
    std::string tema;

public:
    Configuracoes();

    void setNome(const std::string& nome);
    void setTema(const std::string& tema_);

    const std::string& getNome() const;
    const std::string& getTema() const;

    void salvar(const std::string& caminho) const override;
    void carregar(const std::string& caminho) override;
};
