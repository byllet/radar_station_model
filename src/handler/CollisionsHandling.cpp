#include "CollisionsHandling.hpp"
#include <vector>

const double EPSILON = 1.;

void CollisionSignalsWithPlanes(std::vector<std::vector<Signal>>& signals, 
                                 std::vector<AbstractAirObject*> flying_objects)
{
    for (auto& signals_vector: signals)
    for (auto& signal: signals_vector)
    for (auto& flyingObject: flying_objects) {
        if ((flyingObject->GetPosition() - signal.position).Length() < flyingObject->GetDetectionSize()) {
            signal.Reflection();
        }
    }
}
                                 
void CollisionSignalWithReciever(std::vector<std::vector<Signal>>& signals, 
                                 RadioDetectionAndRangingModel& rls)
{
    std::vector<Signal> returned_signals;
    for (auto& signals_vector: signals)
    for (auto& signal: signals_vector) {
        if ((rls.GetPosition() - signal.position).Length() < EPSILON) {
            returned_signals.push_back(signal);
        }
    }

    rls.GetReciever().TakeSignal(returned_signals);
}