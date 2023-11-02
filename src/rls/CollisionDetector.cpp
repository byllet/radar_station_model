#include "CollisionDetector.hpp"
#include <math.h>

CollisionDetector::CollisionDetector() : neighborhood{10.} {}

CollisionDetector::CollisionDetector(double neighborhood) : neighborhood{neighborhood} {}

void CollisionDetector::CheckCollision(Signal signal, AbstractAirObject* plane)
{
    if (std::sqrt(
    std::pow((signal.position.x - plane->GetPosition().x), 2) +
    std::pow((signal.position.y - plane->GetPosition().y), 2) + 
    std::pow((signal.position.z - plane->GetPosition().z), 2)
     ) < neighborhood)
     {
         signal.Reflection();
     }
}