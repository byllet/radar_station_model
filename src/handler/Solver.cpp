#include "Solver.hpp"

Solver::Solver(Manager* m) : manager{m} {}

void Solver::Start(double time)
{
    double dt = 0.1;
    for (double t = 0.; t < time; t += 0.1) {
        Update(dt);
    }
}

void Solver::Update(double dt)
{
    for (auto r: manager->GetFlyingObjects()) {
        r->update(0.1);
    }
}