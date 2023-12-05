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

    void TakeNewSignals(std::vector<Signal>& signals_vec);

    std::vector<Vec3> GetPositionsFromTracker();
    std::vector<Aim> GetAims();

    void SetTimeForRadar(double time); 

private:
    Solver solver;
    RadioDetectionAndRangingModel radar;
    std::vector<AbstractAirObject*> flying_objs;
    std::vector<std::vector<Signal>> signals_vec;
    std::vector<AbstractAirModelPattern*> patterns; //used patterns, what should be free 
    std::unordered_map<AbstractAirObject*, std::queue<AbstractAirModelPattern*>> air_object_patterns;
};
