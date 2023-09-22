#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../Vec3.hpp"

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel() {}
    void Update(float dt);
private:
    Emitter emitter;
    Reciever reciever;
    Vec3 position;
};