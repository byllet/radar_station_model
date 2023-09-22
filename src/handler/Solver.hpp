#pragma once

#include "../Manager.hpp"

class Solver {
public:
    Solver(Manager* m);
    void Start(double time);

private:
    void Update(double dt);
    Manager* manager;
};
