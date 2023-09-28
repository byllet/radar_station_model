#pragma once

#include "../Manager.hpp"

class Solver {
public:
    Solver(Manager* m);
    void Start(double time);

private:
    void Update(double time, double dt);
    void UpdateAirObjects(double dt);
    void UpdateSignals();
    void UpdateRadar();
    Manager* manager;
};
