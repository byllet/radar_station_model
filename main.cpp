#include <iostream>
#include "src/Manager.hpp"
#include "src/patterns/ChangeHeightPattern.hpp"
#include "src/patterns/LinearPattern.hpp"
#include "src/patterns/ReversalPattern.hpp"

int main()
{
    Manager m;
    m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(1));
    m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(30));
    for (unsigned int i = 0; i < 1000000; ++i) {
        m.Update(0.1);
        if (i == 25) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(30));
            m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(5));
            m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(50));
        }
        if (i == 100) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(-50));
            m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(20));
        }
        //std::cout << m.GetFlyingObjects()[0]->GetPosition() << " ";
        //std::cout << m.GetFlyingObjects()[0]->GetVelocity().Length() <<  " ";
    }
    return 0;
}

