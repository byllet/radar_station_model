#include "Radar.hpp"

Radar::Radar() : position{Vec3{0., 0., 0.}} {}

Radar::Radar(Vec3 position) : position{position} {}

Radar::Radar(Radar& radar)
{
    position = radar.position;
}

void Radar::Start() {}

void Radar::Update(double dt) {}

