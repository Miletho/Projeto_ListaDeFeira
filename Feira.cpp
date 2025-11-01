#include "Feira.h"

Feira::Feira(const std::string& n, int q) : nome(n), quantidade(q) {}

std::string Feira::getNome() const { return nome; }
int Feira::getQuantidade() const { return quantidade; }
void Feira::setQuantidade(int q) { quantidade = q; }

