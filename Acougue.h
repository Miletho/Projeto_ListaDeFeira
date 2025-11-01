#ifndef ACOUGUE_H
#define ACOUGUE_H

#include "Feira.h"

class Acougue : public Feira {
	private:
    	std::string corte;
	public:
    	Acougue(const std::string& n, int q, const std::string& c);
    	void exibirInfo() const override;
};

#endif

