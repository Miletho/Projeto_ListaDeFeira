#ifndef FEIRA_H
#define FEIRA_H

#include <string>
#include <iostream>

class Feira {
	protected:
    	std::string nome;
    	int quantidade;

	public:
    	Feira(const std::string& n, int q);
    	virtual ~Feira() = default;

    	std::string getNome() const;
    	int getQuantidade() const;
    	void setQuantidade(int q);

    	virtual void exibirInfo() const = 0;
};

#endif

