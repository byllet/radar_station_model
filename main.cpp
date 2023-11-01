#include <iostream>
#include "src/Manager.hpp"
#include "src/patterns/ChangeHeightPattern.hpp"
#include "src/patterns/LinearPattern.hpp"

int main() 
{
    Manager m;
    
    m.AddNewPattern(m.GetFlyingObjects()[0], new LinearPattern(1));
    m.AddNewPattern(m.GetFlyingObjects()[0], new ChangeHeightPattern(4));
    for (unsigned int i = 0; i < 50; ++i) {
        m.Update(0.1);
    }
    return 0;
}

