#include "Manager.hpp"

#include "air_models/Plane.hpp"
#include "patterns/LinearPattern.hpp"

Manager::Manager() : solver{this}
{
    flying_objs.push_back(new Plane({0, 0, 0}, {2, 2, 0}, {0, 0, 0}));
    //flying_objs.push_back(new Plane({0, 0, 0}, {1, 1, 1}, {0, 0, 0}));
    patterns.push_back(new LinearPattern());
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

void Manager::Update(double time)
{
    solver.Update(time);
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

AbstractAirModelPattern* Manager::GetChosedPattern(AbstractAirObject* air_object)
{
    if (air_object_patterns[air_object].empty()) {
        return patterns[0];
    }
    
    if (air_object_patterns[air_object].front()->GetDuration() <= 0) {
        air_object_patterns[air_object].pop();
        return GetChosedPattern(air_object);
    }

    return air_object_patterns[air_object].front();
}

void Manager::AddNewFlyingObject(AbstractAirObject* obj) 
{
    flying_objs.push_back(obj);
}

void Manager::AddNewPattern(AbstractAirObject* obj, AbstractAirModelPattern* new_pattern)
{
    air_object_patterns[obj].push(new_pattern);
    patterns.push_back(new_pattern);
}
