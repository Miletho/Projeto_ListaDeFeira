#ifndef PRODUTOLIMPEZA_H
#define PRODUTOLIMPEZA_H

#include "Feira.h"

class ProdutoLimpeza : public Feira {
	private:
    	std::string uso;
	public:
    	ProdutoLimpeza(const std::string& n, int q, const std::string& u);
    	void exibirInfo() const override;
};

#endif

