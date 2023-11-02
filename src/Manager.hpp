#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

#include "signal.hpp"
#include "rls/RadioDetectionAndRangingModel.hpp"
#include "air_models/AbstractAirObject.hpp"
#include "handler/Solver.hpp"

class Manager {
public:
    Manager();
    ~Manager();

    void Update(double dt);

    RadioDetectionAndRangingModel& GetRadar();
    std::vector<AbstractAirObject*>& GetFlyingObjects();
    std::vector<std::vector<Signal>>& GetSignals();

    AbstractAirModelPattern* GetChosedPattern(AbstractAirObject* air_object); //pattern manager??

    void AddNewFlyingObject(AbstractAirObject* obj);
    void AddNewPattern(AbstractAirObject* obj, AbstractAirModelPattern* pattern);

private:
    Solver solver;
    RadioDetectionAndRangingModel radar;
    std::vector<AbstractAirObject*> flying_objs;
    std::vector<std::vector<Signal>> signals;
    std::vector<AbstractAirModelPattern*> patterns; //used patterns, what should be free 
    std::unordered_map<AbstractAirObject*, std::queue<AbstractAirModelPattern*>> air_object_patterns;
};