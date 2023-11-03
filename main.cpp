#include <iostream>
#include "src/Manager.hpp"
#include "src/patterns/ChangeHeightPattern.hpp"
#include "src/patterns/LinearPattern.hpp"
#include "src/patterns/ReversalPattern.hpp"

int main()
{
    Manager m;
    // m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(1));
    //m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(4));
    for (unsigned int i = 0; i < 300; ++i) {
        m.Update(0.1);
        if (i == 25) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(3));
            //m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(5));
            m.AddNewPattern(m.GetFlyingObjects()[0], new ReversalPattern(3));
        }
        if (i == 100) {
            m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(-1));
        }
        std::cout << m.GetFlyingObjects()[0]->GetPosition() << ' ';
    }
    return 0;
}

