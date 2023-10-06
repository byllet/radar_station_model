#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"
#include <vector>

class Radar {
public:
    Radar();
    Radar(Vec3 position);
    Radar(Radar& radar);
    void Start();
    void Update(double dt);

public:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
};
