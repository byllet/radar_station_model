#pragma once

class Manager;

class Solver {
public:
    Solver(Manager* m);
    void Update(double dt);

private:
    void UpdateAirObjects(double dt);
    void UpdateSignals(double dt);
    void UpdateRadar(double dt);
    void SolveCollisions(double dt);
    Manager* manager;
};