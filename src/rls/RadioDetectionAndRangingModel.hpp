#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    void Update(float dt);

private:
    Emitter emitter;
    Reciever reciever;
    Vec3 position;
};