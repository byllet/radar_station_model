#include "Solver.hpp"
#include "../Manager.hpp"
#include "CollisionsHandling.hpp"
#include <vector>

Solver::Solver(Manager* m) : manager{m} {}

void Solver::Update(double dt)
{
    SolveCollisions();
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
    for (auto signal = signals_vector.rbegin(); signal != signals_vector.rend(); ++signal) {
        signal->Update(dt);
        if (!signal->alive) {
            signals_vector.erase(signal.base());
        }
    }
}

void Solver::UpdateRadar(double dt) 
{
    std::vector<Signal> s = manager->GetRadar().Update(dt);
    manager->TakeNewSignals(s);
}

void Solver::SolveCollisions() 
{
    CollisionSignalsWithPlanes(manager->GetSignals(), manager->GetFlyingObjects());
    CollisionSignalWithReciever(manager->GetSignals(), manager->GetRadar());
}