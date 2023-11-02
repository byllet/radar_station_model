#include "Solver.hpp"
#include "../Manager.hpp"

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
        //manager->GetChosedPattern(flyingObject)->SetDuration(manager->GetChosedPattern(flyingObject)->GetDuration() - dt);
    }
}

void Solver::UpdateSignals(double dt) {}

void Solver::UpdateRadar(double dt) {}

void Solver::SolveCollisions() {}