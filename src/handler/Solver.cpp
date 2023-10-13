#include "Solver.hpp"

Solver::Solver(Manager* m) : manager{m} {}

void Solver::Start(double time)
{
    double dt = 0.1;
    Update(time, dt);
}

void Solver::Update(double time, double dt)
{
    for (double t = 0; t < time; t += dt) {
        SolveCollisions();
        UpdateAirObjects(dt);
        UpdateSignals(dt);
        UpdateRadar(dt);
    }
}

void Solver::UpdateAirObjects(double dt)
{
    for (auto flyingObject: manager->GetFlyingObjects()) {
        flyingObject->SetPattern(manager->GetChosedPattern());
        flyingObject->Update(dt);
        manager->GetChosedPattern()->SetDuration(manager->GetChosedPattern()->GetDuration() - dt);
    }
}

void Solver::UpdateSignals(double dt) {}

void Solver::UpdateRadar(double dt) {}

void Solver::SolveCollisions() {}
