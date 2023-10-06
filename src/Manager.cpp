#include "Manager.hpp"

#include "air_models/Plane.hpp"
#include "handler/Solver.hpp"
#include "patterns/LinearPattern.hpp"
#include "patterns/ChangeHeightPattern.hpp"

Manager::Manager()
{
    flying_objs.push_back(new Plane({0, 0, 0}, {2, 2, 0}, {0, 0, 0}));
    patterns.push_back(new LinearPattern());
    patterns.push_back(new ChangeHeightPattern(10));
    chosed_pattern = patterns[0];
}

Manager::~Manager()
{
    for (auto fo: flying_objs) {
        delete fo;
    }
    
    for (auto p: patterns) {
        delete p;
    }
}

void Manager::StartSimulation(double time)
{
    Solver solver(this);
    solver.Start(time);
}

RadioDetectionAndRangingModel& Manager::GetRadar()
{
    return radar;
}

std::vector<AbstractAirObject*>& Manager::GetFlyingObjects()
{
    return flying_objs;
}

std::vector<Signal*>& Manager::GetSignals()
{
    return signals;
}

AbstractAirModelPattern* Manager::GetChosedPattern()
{
    return chosed_pattern;
}
