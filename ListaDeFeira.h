#ifndef LISTADEFEIRA_H
#define LISTADEFEIRA_H

#include <vector>
#include <memory>
#include "Feira.h"

class ListaDeFeira {
private:
    std::vector<std::shared_ptr<Feira>> itens;

public:
    void adicionar(std::shared_ptr<Feira> f);
    void listar() const;
    void atualizar(const std::string& nome);
    void remover(const std::string& nome);
};

#endif
