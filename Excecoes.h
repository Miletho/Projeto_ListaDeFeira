#pragma once
#include <stdexcept>
#include <string>

class ErroItemInvalido : public std::runtime_error {
public:
    explicit ErroItemInvalido(const std::string& msg)
        : std::runtime_error("Item inválido: " + msg) {}
};

class ErroItemDuplicado : public std::runtime_error {
public:
    explicit ErroItemDuplicado(const std::string& nome)
        : std::runtime_error("O item '" + nome + "' já está na lista.") {}
};

class ErroItemNaoEncontrado : public std::runtime_error {
public:
    explicit ErroItemNaoEncontrado(const std::string& nome)
        : std::runtime_error("O item '" + nome + "' não foi encontrado.") {}
};

class ErroConfiguracao : public std::runtime_error {
public:
    explicit ErroConfiguracao(const std::string& msg)
        : std::runtime_error("Erro de configuração: " + msg) {}
};

class ErroArquivo : public std::runtime_error {
public:
    explicit ErroArquivo(const std::string& msg)
        : std::runtime_error("Erro de arquivo: " + msg) {}
};
