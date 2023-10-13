#include "Manager.hpp"

#include "air_models/Plane.hpp"
#include "handler/Solver.hpp"
#include "patterns/DefaultPattern.hpp"

Manager::Manager()
{
    flying_objs.push_back(new Plane({10, 10, 10}, {10, 0, 0}, {0, 0, 0}));
    patterns.push_back(new DefaultPattern());
    chosed_pattern = patterns[0];
}

Manager::~Manager()
{
    for (unsigned int i = 0; i < flying_objs.size(); ++i) {
        delete flying_objs[i];
    }
    
    for (unsigned int i = 0; i < patterns.size(); ++i) {
        delete patterns[i];
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