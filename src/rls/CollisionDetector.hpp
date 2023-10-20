#include "../air_models/Plane.hpp"
#include "../Signal.hpp"

class CollisionDetector
{
public:
    CollisionDetector();
    CollisionDetector(double neighborhood);
    void CheckCollision(Signal signal, Plane plane);
private:
    double neighborhood;
};