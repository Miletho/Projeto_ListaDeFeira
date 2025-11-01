#include "App.h"
#include <iostream>
#include <limits>
#include <stdexcept>

void App::menuAdicionar() {
    int tipo;
    std::cout << "1. Hortaliça\n2. Alimento Base\n3. Açougue\n4. Produto de Limpeza\n5. Doce\nEscolha o tipo: ";
    if (!(std::cin >> tipo)) throw std::invalid_argument("Entrada inválida!");

    std::string nome;
    int qtd;

    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    std::cout << "Quantidade: ";
    if (!(std::cin >> qtd)) throw std::invalid_argument("Entrada inválida!");

    if (tipo == 1) {
        char resp;
        std::cout << "É orgânica (s/n)? ";
        std::cin >> resp;
        bool org = (resp == 's' || resp == 'S');
        lista.adicionar(std::make_shared<Hortalica>(nome, qtd, org));
    }
    else if (tipo == 2) {
        lista.adicionar(std::make_shared<AlimentoBase>(nome, qtd));
    }
    else if (tipo == 3) {
        std::string corte;
        std::cout << "Tipo de corte: ";
        std::cin.ignore();
        std::getline(std::cin, corte);
        lista.adicionar(std::make_shared<Acougue>(nome, qtd, corte));
    }
    else if (tipo == 4) {
        std::string uso;
        std::cout << "Uso (ex: cozinha, banheiro...): ";
        std::cin.ignore();
        std::getline(std::cin, uso);
        lista.adicionar(std::make_shared<ProdutoLimpeza>(nome, qtd, uso));
    }
    else if (tipo == 5) {
        std::string sabor;
        std::cout << "Sabor do doce: ";
        std::cin.ignore();
        std::getline(std::cin, sabor);
        lista.adicionar(std::make_shared<Doce>(nome, qtd, sabor));
    }
    else {
        throw std::invalid_argument("Opção inválida!");
    }
}

void App::executar() {
    int opc;
    do {
        std::cout << "\n====== LISTA DE FEIRA ======\n";
        std::cout << "1. Adicionar item\n";
        std::cout << "2. Listar itens\n";
        std::cout << "3. Atualizar item\n";
        std::cout << "4. Remover item\n";
        std::cout << "0. Sair\nEscolha: ";
        if (!(std::cin >> opc)) throw std::invalid_argument("Entrada inválida!");

        try {
            switch (opc) {
                case 1: menuAdicionar(); break;
                case 2: lista.listar(); break;
                case 3: {
                    std::string nome;
                    std::cout << "Nome do item a atualizar: ";
                    std::cin.ignore();
                    std::getline(std::cin, nome);
                    lista.atualizar(nome);
                    break;
                }
                case 4: {
                    std::string nome;
                    std::cout << "Nome do item a remover: ";
                    std::cin.ignore();
                    std::getline(std::cin, nome);
                    lista.remover(nome);
                    break;
                }
                case 0: std::cout << "Saindo...\n"; break;
                default: throw std::invalid_argument("Opção inválida!");
            }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "⚠️ Erro de argumento: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::logic_error& e) {
            std::cerr << "⚠️ Erro lógico: " << e.what() << std::endl;
        }

    } while (opc != 0);
}
