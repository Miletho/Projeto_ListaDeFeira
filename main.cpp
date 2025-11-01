#include "App.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    try {
        App app;
        app.executar();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Erro de argumento capturado no main: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Erro lógico capturado no main: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    return 0;
}

