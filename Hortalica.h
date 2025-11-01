#ifndef HORTALICA_H
#define HORTALICA_H

#include "Feira.h"

class Hortalica : public Feira {
private:
    bool organica;
public:
    Hortalica(const std::string& n, int q, bool o);
    void exibirInfo() const override;
};

#endif

