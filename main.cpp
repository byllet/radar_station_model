#include <cmath>
#include <iostream>

#include "src/Manager.hpp"
#include "src/patterns/ChangeHeightPattern.hpp"
#include "src/patterns/LinearPattern.hpp"
#include "src/patterns/ReversalPattern.hpp"
#include "src/utils/Logger.hpp"
#include "src/air_models/Plane.hpp"

int main()
{
    Manager m;
    Logger l(&m);
    m.AddNewFlyingObject(new Plane({20, 20, 5}, {0.5, 0, 0}, {0, 0, 0}));
    m.AddNewFlyingObject(new Plane({50, 10, 10}, {0.5, 0.5, 0}, {0, 0, 0}));
    // m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(1));
    // m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(50));
    
    for (unsigned int i = 0; i < 600; ++i) {
        m.Update(0.33);

        // if (i == 25) {
        //     m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(50));
        //     m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(5));
        //     m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(100));
        //     for (auto& s : m.GetSignals()[1]) {
        //         std::cout << s.position << " ";
        //     }
        // }
        // if (i == 100) {
        //     m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(-50));
        //     m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(100));
        // }
        // std::cout << m.GetFlyingObjects()[0]->GetPosition() << " ";
        // //std::cout << m.GetFlyingObjects()[0]->GetVelocity().Length() <<  " ";
    }
    return 0;
}

