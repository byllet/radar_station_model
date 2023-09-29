#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"
#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    void Start();
    void Update(double dt);

private:
    Emitter emitter;
    Reciever reciever;
    Vec3 position;
};
