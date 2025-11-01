#ifndef ALIMENTOBASE_H
#define ALIMENTOBASE_H

#include "Feira.h"

class AlimentoBase : public Feira {
	public:
    	AlimentoBase(const std::string& n, int q);
    	void exibirInfo() const override;
};

#endif

