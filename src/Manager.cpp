#include "Manager.hpp"

#include "air_models/Plane.hpp"
#include "patterns/LinearPattern.hpp"
#include <vector>

Manager::Manager() : solver{this}, radar{{Vec3()}}
{
    patterns.push_back(new LinearPattern());
    //flying_objs.push_back(new Plane({0, 0, 0}, {100, 100, 100}, {0, 0, 0}));
    signals_vec.push_back(radar.Start(1000));
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

void Manager::Update(double dt)
{
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

std::vector<std::vector<Signal>>& Manager::GetSignals()
{
    return signals_vec;
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

void Manager::TakeNewSignals(std::vector<Signal>& signals_v)
{
    signals_vec.push_back(signals_v);
}

std::vector<Vec3> Manager::GetPositionsFromTracker()
{
    return radar.GetReciever().GetTracker().GetAimsPositions();
}

void Manager::SetTimeForRadar(double time)
{
    radar.SetDeparturePeriod(time);
}