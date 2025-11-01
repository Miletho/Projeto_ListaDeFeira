#ifndef DOCE_H
#define DOCE_H

#include "Feira.h"

class Doce : public Feira {
private:
    bool light;
public:
    Doce(const std::string& n, int q, bool l);
    void exibirInfo() const override;
};

#endif

