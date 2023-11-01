#include <iostream>
#include "src/Manager.hpp"
#include "src/patterns/ReversalPattern.hpp"

int main() 
{
    Manager m;
    m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(4));
    for (unsigned int i = 0; i < 3; ++i) {
        m.Update(0.2);
    }

    
    return 0;
}

// #include <iostream>
// #include <vector>
// #include "src/tracker/Tracker.hpp"

// int main() 
// {
//     Tracker t;
//     size_t n = 30;
//     std::vector<Vec3> pos1(n);
//     std::vector<Vec3> pos2(n);

//     double dt = 0.1;
//     for (unsigned int i = 0; i < n; ++i) {
//         pos1[i] = Vec3{0. + 1 * i * dt + i * i * dt * dt, 0., 0.};
//         pos2[i] = Vec3{ 15 * dt - i * dt, 0. + i * dt, 0.};
//     }

//     for (unsigned int i = 0; i < n; ++i) {
//         std::vector<Vec3> p = {pos1[i]};
//         t.TakeRawData(p, dt);
//     }
//     return 0;
// }
