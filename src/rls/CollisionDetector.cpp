#include "CollisionDetector.hpp"
#include <math.h>

CollisionDetector::CollisionDetector() : neighborhood{10.} {}

CollisionDetector::CollisionDetector(double neighborhood) : neighborhood{neighborhood} {}

void CollisionDetector::CheckCollision(Signal signal, Plane plane)
{
    if (std::sqrt(
    std::pow((signal.position.X() - plane.GetPosition().X()), 2) +
    std::pow((signal.position.Y() - plane.GetPosition().X()), 2) + 
    std::pow((signal.position.Z() - plane.GetPosition().X()), 2)
     ) < neighborhood)
     {
         signal.Reflection();
     }
}