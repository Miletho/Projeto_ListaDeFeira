#ifndef LISTADEFEIRA_H
#define LISTADEFEIRA_H

#include <vector>
#include <string>
#include "Feira.h"

class ListaDeFeira {
	private:
    	std::vector<Feira*> itens;

	public:
    	~ListaDeFeira();	
    	void adicionar(Feira* item);
    	void listar() const;
    	void remover(const std::string& nome);
    	void atualizar(const std::string& nome, int novaQuantidade);
};

#endif

