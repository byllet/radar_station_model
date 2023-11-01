#pragma once

#include "Manager.hpp"
#include "handler/Solver.hpp"
#include "air_models/Plane.hpp"
#include "handler/Solver.hpp"
#include "patterns/LinearPattern.hpp"
#include "patterns/ChangeHeightPattern.hpp"
#include "patterns/ReversalPattern.hpp"

Manager::Manager()
{
//    flying_objs.push_back(new Plane({0, 0, -1.5}, {0.001, -0.003, -0.007}, {0, 0, 0}));
    patterns.push_back(new LinearPattern());
    patterns.push_back(new ChangeHeightPattern(10));
    patterns.push_back(new ReversalPattern(4));

    patterns[0]->SetDuration(2);
    q_patterns.push(patterns[0]);

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

void Manager::AddFlyingObject(Plane* new_object)
{
    flying_objs.push_back(static_cast<AbstractAirObject*>(new_object));
}

void Manager::Update(double dt)
{
    Solver solver(this);
    solver.Update(dt);
}

RadioDetectionAndRangingModel& Manager::GetRadar()
{
    return radar;
}

std::vector<AbstractAirObject*>& Manager::GetFlyingObjects()
{
    return flying_objs;
}

//std::vector<Signal*>& Manager::GetSignals()
//{
//    return signals;
//}

AbstractAirModelPattern* Manager::GetChosedPattern()
{
    if (q_patterns.front()->GetDuration() <= 0) {
        q_patterns.pop();
    }
    
    if (q_patterns.empty()) {
        return patterns[0];
    }
    return q_patterns.front();
}
