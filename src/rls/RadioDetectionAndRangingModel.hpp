#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"

#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    RadioDetectionAndRangingModel(Vec3 position);
    RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar);

    std::vector<Signal> Start();
    void Update(double dt);

    Reciever& GetReciever();
    Emitter& GetEmitter();
    Vec3 GetPosition();

private:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
};
