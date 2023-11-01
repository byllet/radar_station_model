#pragma once

#include <queue>
#include <vector>
#include <algorithm>
//#include "signal.hpp"
#include "rls/RadioDetectionAndRangingModel.hpp"
#include "air_models/Plane.hpp"

class Manager {

public:
    Manager();
    ~Manager();

    void AddFlyingObject(Plane*);
    void Update(double dt);

    RadioDetectionAndRangingModel& GetRadar();
    std::vector<AbstractAirObject*>& GetFlyingObjects();
    std::vector<Signal*>& GetSignals();
    AbstractAirModelPattern* GetChosedPattern();

private:
    RadioDetectionAndRangingModel radar;
    std::vector<AbstractAirObject*> flying_objs;
//    std::vector<Signal*> signals;
    std::vector<AbstractAirModelPattern*> patterns;
    std::queue<AbstractAirModelPattern*> q_patterns;
};
