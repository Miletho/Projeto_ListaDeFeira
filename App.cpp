#include "App.h"
#include "Configuracoes.h"
#include "Hortalica.h"
#include "AlimentoBase.h"
#include "Acougue.h"
#include "ProdutoLimpeza.h"
#include "Doce.h"
#include "Remedio.h"
#include "Roupa.h"
#include "Higiene.h"

#include <iostream>
#include <limits>
#include <memory>

extern Configuracoes configGlobal;

int App::lerInteiro() {
    int v;
    while (!(std::cin >> v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erro: Entrada invalida. Digite um numero inteiro: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return v;
}

double App::lerDouble() {
    double v;
    while (!(std::cin >> v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erro: Entrada invalida. Digite um numero: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return v;
}

void App::limparEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void App::menuAdicionar() {
    std::cout << "\n--- Adicionar item à lista ---\n"
              << "1. Hortaliça\n"
              << "2. Alimento Base\n"
              << "3. Açougue\n"
              << "4. Produto de Limpeza\n"
              << "5. Doce\n"
              << "6. Remedio\n"
              << "7. Roupa\n"
              << "8. Higiene\n"
              << "Escolha o tipo (1-8): " << std::flush;

    int tipo = lerInteiro();

    std::string nome;
    std::cout << "Nome: ";
    std::getline(std::cin, nome);

    std::cout << "Quantidade: ";
    double quantidade = lerDouble();

    std::shared_ptr<ItemBase> item = nullptr;

    switch (tipo) {
        case 1: {
            std::cout << "Organica (s/n)? ";
            char c; std::cin >> c; limparEntrada();
            bool organica = (c == 's' || c == 'S');
            item = std::make_shared<Hortalica>(nome, quantidade, organica);
            break;
        }
        case 2: {
            item = std::make_shared<AlimentoBase>(nome, quantidade);
            break;
        }
        case 3: {
            std::string corte;
            std::cout << "Tipo de corte: ";
            std::getline(std::cin, corte);
            item = std::make_shared<Acougue>(nome, quantidade, corte);
            break;
        }
        case 4: {
            std::string uso;
            std::cout << "Uso (ex.: banheiro, cozinha): ";
            std::getline(std::cin, uso);
            item = std::make_shared<ProdutoLimpeza>(nome, quantidade, uso);
            break;
        }
        case 5: {
            std::cout << "Light (s/n)? ";
            char c; std::cin >> c; limparEntrada();
            bool light = (c == 's' || c == 'S');
            item = std::make_shared<Doce>(nome, quantidade, light);
            break;
        }
        case 6: {
            std::string uso;
            std::cout << "Uso (TDAH, antiflamatorio): ";
            std::getline(std::cin, uso);
            item = std::make_shared<Remedio>(nome, quantidade, uso);
            break;
        }
        case 7: {
            std::string tamanho;
            std::cout << "Tamanho: ";
            std::getline(std::cin, tamanho);
            item = std::make_shared<Roupa>(nome, quantidade, tamanho);
            break;
        }
        case 8: {
            std::string uso;
            std::cout << "Uso (rosto, corpo): ";
            std::getline(std::cin, uso);
            item = std::make_shared<Higiene>(nome, quantidade, uso);
            break;
        }
        default:
            std::cout << "Opcao invalida.\n";
            return;
    }

    if (lista.adicionarItem(item)) {
        std::cout << "Item adicionado com sucesso!\n";
    }
}

void App::menuListar() {
    lista.listarItens();
}

void App::menuAtualizar() {
    std::cout << "Nome do item: ";
    std::string nome;
    std::getline(std::cin, nome);

    std::cout << "Nova quantidade: ";
    double q = lerDouble();

    if (lista.atualizarQuantidade(nome, q))
        std::cout << "Quantidade atualizada!\n";
    else
        std::cout << "Item nao encontrado.\n";
}

void App::menuRemover() {
    std::cout << "Nome do item para remover: ";
    std::string nome;
    std::getline(std::cin, nome);

    if (lista.removerItem(nome))
        std::cout << "Item removido.\n";
    else
        std::cout << "Item nao encontrado.\n";
}

void App::executar() {
    int opcao = -1;
    do {
        std::cout << "\n==== LISTA DE FEIRA ====\n"
                << "1. Adicionar item\n"
                << "2. Listar itens\n"
                << "3. Atualizar quantidade\n"
                << "4. Remover Item\n"
                << "5. Configuracoes\n"
                << "6. Sair\n"
                << "Escolha uma opcao: " << std::flush;

        opcao = lerInteiro();

        switch (opcao) {
            case 1: menuAdicionar(); break;
            case 2: menuListar(); break;
            case 3: menuAtualizar(); break;
            case 4: menuRemover(); break;
            case 5: abrirConfiguracoes(); break;
            case 6: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opcao invalida.\n";
        }

    } while (opcao != 6);
}

void App::abrirConfiguracoes() {
    int opc=0;
    do {
        std::cout << "\n--- Configuracoes ---\n";
        std::cout << "1. Alterar nome do usuario\n";
        std::cout << "2. Alterar tema (claro/escuro)\n";
        std::cout << "3. Voltar\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opc;
        std::cin.ignore();

        if (opc == 1) {
            std::string nome;
            std::cout << "Digite o novo nome: ";
            std::getline(std::cin, nome);
            configGlobal.setNome(nome);
            std::cout << "Nome atualizado!\n";
        }
        else if (opc == 2) {
            std::string tema;
            std::cout << "Digite o tema (claro ou escuro): ";
            std::getline(std::cin, tema);
            configGlobal.setTema(tema);
            std::cout << "Tema atualizado!\n";
        }

    } while (opc != 3);
}
