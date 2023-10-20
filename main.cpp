#include <iostream>
#include <vector>
#include "src/tracker/Tracker.hpp"

int main() 
{
    Tracker t;
    unsigned int n = 15;
    std::vector<Vec3> pos(n);
    double dt = 0.4;
    for (unsigned int i = 0; i < n; ++i) {
        pos[i] = Vec3{0. + i * dt, 0. + i * dt, 0. + i * dt};
    }
    for (unsigned int i = 0; i < n; ++i) {
        std::vector<Vec3> p = {pos[i]};
        t.TakeRawData(p, dt);
    }
    return 0;
}
