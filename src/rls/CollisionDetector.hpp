#include "../air_models/AbstractAirObject.hpp"
#include "../Signal.hpp"

class CollisionDetector
{
public:
    CollisionDetector();
    CollisionDetector(double neighborhood);
    void CheckCollision(Signal signal, AbstractAirObject* plane);
private:
    double neighborhood;
};