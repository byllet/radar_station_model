#include "Solver.hpp"
#include "../Manager.hpp"
#include "CollisionsHandling.hpp"

Solver::Solver(Manager* m) : manager{m} {}

void Solver::Update(double dt)
{
    UpdateAirObjects(dt);
    UpdateSignals(dt);
    UpdateRadar(dt);
    SolveCollisions();
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
    bool is_signals_alive = true;
    for (auto& signals_vector: manager->GetSignals())
        for (auto signal_iter = 0; signal_iter < signals_vector.size(); ++signal_iter) {
        signals_vector[signal_iter].Update(dt);
        if (!signals_vector[signal_iter].alive) {
            is_signals_alive = false;
//            signals_vector.erase(signals_vector.begin() + signal_iter);
            break;
        }
    }
    if (!is_signals_alive) {
        manager->GetSignals().erase(manager->GetSignals().begin());
        manager->GetSignals().push_back(manager->GetRadar().Start());
    }
}

void Solver::UpdateRadar(double dt) 
{
    manager->GetRadar().Update(dt);
}

void Solver::SolveCollisions() 
{
    CollisionSignalsWithPlanes(manager->GetSignals(), manager->GetFlyingObjects());
    CollisionSignalWithReciever(manager->GetSignals(), manager->GetRadar());
}
