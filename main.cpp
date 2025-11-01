#include "App.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    App app;
    app.executar();

    return 0;
}
