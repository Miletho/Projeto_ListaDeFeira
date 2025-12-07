#pragma once

#include <iostream>

class IExibivel {
public:
    virtual void exibirInfo() const = 0;
    virtual ~IExibivel() = default;
};
