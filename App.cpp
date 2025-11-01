#include <iostream>
#include <memory>
#include <limits>
#include "App.h"
#include "Hortalica.h"
#include "AlimentoBase.h"
#include "Acougue.h"
#include "ProdutoLimpeza.h"
#include "Doce.h"

App::App() {}

void App::menuAdicionar() {
    int tipo;
    std::cout << std::endl << "--- Adicionar item à feira ---" << std::endl;
    std::cout << "1. Hortaliça" << std::endl;
    std::cout << "2. Alimento Base" << std::endl;
    std::cout << "3. Açougue" << std::endl;
    std::cout << "4. Produto de Limpeza" << std::endl;
    std::cout << "5. Doce" << std::endl;
    std::cout << "Escolha o tipo (1-5): " << std::flush;

    if (!(std::cin >> tipo)) {
        throw std::invalid_argument("Entrada inválida: espere um número inteiro.");
    }

    std::string nome;
    int quantidade;

    std::cout << "Nome: " << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa buffer
    std::getline(std::cin, nome);

    std::cout << "Quantidade: " << std::flush;
    if (!(std::cin >> quantidade)) {
        throw std::invalid_argument("Entrada inválida: espere um número inteiro.");
    }

    if (quantidade <= 0) {
        throw std::logic_error("Quantidade deve ser um número positivo.");
    }

    std::shared_ptr<Feira> item;

    switch (tipo) {
        case 1: {
            char resp;
            std::cout << "É orgânica (s/n)? " << std::flush;
            std::cin >> resp;
            bool organico = (resp == 's' || resp == 'S');
            item = std::make_shared<Hortalica>(nome, quantidade, organico);
            break;
        }
        case 2:
            item = std::make_shared<AlimentoBase>(nome, quantidade);
            break;
        case 3: {
            std::string corte;
            std::cout << "Tipo de corte: " << std::flush;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, corte);
            item = std::make_shared<Acougue>(nome, quantidade, corte);
            break;
        }
        case 4: {
            std::string uso;
            std::cout << "Tipo de uso: " << std::flush;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, uso);
            item = std::make_shared<ProdutoLimpeza>(nome, quantidade, uso);
            break;
        }
        case 5: {
            char resp;
            std::cout << "É light (s/n)? " << std::flush;
            std::cin >> resp;
            bool light = (resp == 's' || resp == 'S');
            item = std::make_shared<Doce>(nome, quantidade, light);
            break;
        }
        default:
            throw std::logic_error("Opção fora do intervalo permitido!");
    }

    lista.adicionar(item);
    std::cout << "Item adicionado com sucesso!\n";
}

void App::executar() {
    int opcao;

    do {
        std::cout << std::endl << "==== LISTA DE FEIRA ====" << std::endl;
        std::cout << "1. Adicionar item" << std::endl;
        std::cout << "2. Listar itens" << std::endl;
        std::cout << "3. Atualizar quantidade" << std::endl;
        std::cout << "4. Remover item" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opção: " << std::flush;  // 🔹 força exibição imediata

        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Erro: Entrada inválida! Digite um número." << std::endl;
            continue;
        }

        try {
            switch (opcao) {
                case 1:
                    menuAdicionar();
                    break;
                case 2:
                    lista.listar();
                    break;
                case 3: {
                    std::string nome;
                    int novaQuantidade;
                    std::cout << "Nome do item: " << std::flush;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nome);
                    std::cout << "Nova quantidade: " << std::flush;
                    if (!(std::cin >> novaQuantidade)) {
                        throw std::invalid_argument("Entrada inválida: espere um número inteiro.");
                    }
                    lista.atualizar(nome, novaQuantidade);
                    break;
                }
                case 4: {
                    std::string nome;
                    std::cout << "Nome do item para remover: " << std::flush;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nome);
                    lista.remover(nome);
                    break;
                }
                case 5:
                    std::cout << "Saindo..." << std::endl;
                    break;
                default:
                    throw std::logic_error("Opção fora do intervalo permitido!");
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const std::logic_error& e) {
            std::cerr << "Erro lógico: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Erro inesperado!" << std::endl;
        }

        // 🔹 garante que o buffer de saída seja exibido antes do próximo loop
        std::cout << std::flush;

    } while (opcao != 5);
}
