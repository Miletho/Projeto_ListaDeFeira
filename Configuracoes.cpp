#include "Configuracoes.h"
#include "Excecoes.h"
#include <fstream>
#include <iostream>

Configuracoes::Configuracoes()
    : nomeUsuario("Usuario"), tema("claro") {}

void Configuracoes::setNome(const std::string& nome) {
    nomeUsuario = nome;
}

void Configuracoes::setTema(const std::string& tema_) {
    if (tema_ == "claro" || tema_ == "escuro")
        tema = tema_;
}

const std::string& Configuracoes::getNome() const {
    return nomeUsuario;
}

const std::string& Configuracoes::getTema() const {
    return tema;
}

void Configuracoes::salvar(const std::string& caminho) const {
    std::ofstream arq(caminho);

    if (!arq) {
        throw ErroArquivo("Falha ao salvar arquivo: " + caminho);
    }

    if (nomeUsuario.empty()) {
        throw ErroConfiguracao("Nome de usuário não pode ser vazio ao salvar.");
    }

    arq << nomeUsuario << "\n";
    arq << tema << "\n";
}

void Configuracoes::carregar(const std::string& caminho) {
    std::ifstream arq(caminho);

    if (!arq) {
        throw ErroArquivo("Arquivo de configuração não encontrado: " + caminho);
    }

    std::string nomeLido;
    std::string temaLido;

    std::getline(arq, nomeLido);
    std::getline(arq, temaLido);

    if (nomeLido.empty()) {
        throw ErroConfiguracao("Nome de usuário inválido no arquivo de configuração.");
    }

    if (temaLido != "claro" && temaLido != "escuro") {
        throw ErroConfiguracao("Tema inválido encontrado no arquivo: " + temaLido);
    }

    nomeUsuario = nomeLido;
    tema = temaLido;
}
