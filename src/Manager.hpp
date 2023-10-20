#pragma once

#include <queue>
#include <vector>
#include "signal.hpp"
#include "rls/RadioDetectionAndRangingModel.hpp"
#include "air_models/AbstractAirObject.hpp"

class Manager {
public:
    Manager();
    ~Manager();

    void StartSimulation(double time);

    RadioDetectionAndRangingModel& GetRadar();
    std::vector<AbstractAirObject*>& GetFlyingObjects();
    std::vector<Signal*>& GetSignals();

    AbstractAirModelPattern* GetChosedPattern();

    void AddNewFlyingObject(AbstractAirObject* obj);

private:
    RadioDetectionAndRangingModel radar;
    std::vector<AbstractAirObject*> flying_objs;
    std::vector<Signal*> signals;
    std::vector<AbstractAirModelPattern*> patterns; 
    std::queue<AbstractAirModelPattern*> q_patterns;
};
