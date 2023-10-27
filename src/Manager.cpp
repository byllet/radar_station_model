#include "Manager.hpp"

#include "air_models/Plane.hpp"
#include "handler/Solver.hpp"
#include "patterns/LinearPattern.hpp"
#include "patterns/ChangeHeightPattern.hpp"
#include "patterns/ReversalPattern.hpp"

Manager::Manager()
{
    flying_objs.push_back(new Plane({0, 0, 0}, {2, 2, 0}, {0, 0, 0}));
    patterns.push_back(new LinearPattern());
    patterns.push_back(new ChangeHeightPattern(10));
    patterns.push_back(new ReversalPattern(4));


    patterns[0]->SetDuration(1);
    q_patterns.push(patterns[0]);
    patterns[2]->SetDuration(5);
    q_patterns.push(patterns[2]);

}

Manager::~Manager()
{
    for (auto f_o: flying_objs) {
        delete f_o;
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
    if (q_patterns.empty()) {
        return patterns[0];
    }
    
    if (q_patterns.front()->GetDuration() <= 0) {
        q_patterns.pop();
        return GetChosedPattern();
    }

    return q_patterns.front();
}

void Manager::AddNewFlyingObject(AbstractAirObject* obj) 
{
    flying_objs.push_back(obj);
}
