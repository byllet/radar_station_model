#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"
#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    RadioDetectionAndRangingModel(Vec3 position, Emitter emitter, Reciever reciever);
    RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar);
    void Start();
    void Update(double dt);

public:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
};
