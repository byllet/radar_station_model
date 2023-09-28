#pragma once

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
    std::vector<Signal>& GetSignals();
    AbstractAirModelPattern* GetChosedPattern();

private:
    RadioDetectionAndRangingModel radar;
    std::vector<AbstractAirObject*> flying_objs;
    std::vector<Signal> signals;
    std::vector<AbstractAirModelPattern*> patterns; 
    AbstractAirModelPattern* chosed_pattern;
};