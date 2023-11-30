#include "Solver.hpp"
#include "../Manager.hpp"
#include "CollisionsHandling.hpp"
#include <vector>

Solver::Solver(Manager* m) : manager{m} {}

void Solver::Update(double dt)
{
    SolveCollisions(dt);
    UpdateAirObjects(dt);
    UpdateSignals(dt);
    UpdateRadar(dt);
}

void Solver::UpdateAirObjects(double dt)
{
    for (auto& flyingObject: manager->GetFlyingObjects()) {
        flyingObject->SetPattern(manager->GetChosedPattern(flyingObject));
        flyingObject->Update(dt);
        double duration = flyingObject->GetPattern()->GetDuration();
        flyingObject->GetPattern()->SetDuration(duration - dt);
    }
}

void Solver::UpdateSignals(double dt) 
{
    for (auto& signals_vector: manager->GetSignals())
    for (long long i = signals_vector.size() - 1; i > -1; --i) {
        signals_vector[i].Update(dt);
        if (!signals_vector[i].alive) {
            signals_vector.erase(signals_vector.begin() + i);
        }
    }
    for (long long i = manager->GetSignals().size() - 1; i > -1; --i) {
        if (manager->GetSignals()[i].empty()) {
            manager->GetSignals().erase(manager->GetSignals().begin() + i);
        }
    }
}

void Solver::UpdateRadar(double dt) 
{
    std::vector<Signal> s;
    manager->GetRadar().Update(dt, s);
    if (!s.empty()) {
        manager->TakeNewSignals(s);
    }
}

void Solver::SolveCollisions(double dt) 
{
    CollisionSignalsWithPlanes(manager->GetSignals(), manager->GetFlyingObjects());
    CollisionSignalWithReciever(manager->GetSignals(), manager->GetRadar(), dt);
}