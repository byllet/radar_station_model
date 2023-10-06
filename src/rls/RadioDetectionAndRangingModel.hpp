#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"
#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel(Vec3 position);
    RadioDetectionAndRangingModel();
    void Start();
    void Update(double dt);

private:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
};
