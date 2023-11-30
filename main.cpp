#include <cmath>
#include <iostream>

#include "src/Manager.hpp"
#include "src/patterns/ChangeHeightPattern.hpp"
#include "src/patterns/LinearPattern.hpp"
#include "src/patterns/ReversalPattern.hpp"
#include "src/utils/Logger.hpp"
#include "src/air_models/Plane.hpp"

//#include "src/Signal.hpp"

int main()
{
    // Signal s{{0, 0, 0}, {1 / std::sqrt(2), 1 / std::sqrt(2), 0}, 100};
    // s.velocity = 1;
    // Vec3 plane = {10, 10, 0};
    // Vec3 O = {0, 0, 0};
    // Vec3 prediction;
    // for (unsigned int i = 0; i < 100; ++i) {
    //     s.Update(0.1);
    //     if ((s.position - plane).Length() < 1) {
    //         s.Reflection();
    //     }
    //     if (s.IsReflected() && (s.position - O).Length() < 1) {
    //         prediction = -1 * s.direction * (s.lifetime / 2); 
    //     }
    // }
    Manager m;
    Logger l(&m);
    m.AddNewFlyingObject(new Plane({0, 0, 300}, {50, 50, 0}, {0, 0, 0}));
    m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(1));
    m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(300));
    
    for (unsigned int i = 0; i < 300; ++i) {
        m.Update(0.33);
        l.Update();
        if (i == 25) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(300));
            m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(5));
            m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(100));
        }
        if (i == 100) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(-50));
            m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(1000));
        }
        std::cout << m.GetFlyingObjects()[0]->GetPosition() << " ";
        //std::cout << m.GetFlyingObjects()[0]->GetVelocity().Length() <<  " ";
    }
    return 0;
}

