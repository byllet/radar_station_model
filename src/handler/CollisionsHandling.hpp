#pragma once

#include "../air_models/AbstractAirObject.hpp"
#include "../Signal.hpp"
#include "../rls/RadioDetectionAndRangingModel.hpp"

#include <vector>

void CollisionSignalsWithPlanes(std::vector<std::vector<Signal>>& signals_vec,
                                 std::vector<AbstractAirObject*> flying_objects);

void CollisionSignalWithReciever(std::vector<std::vector<Signal>>& signals_vec,
                                 RadioDetectionAndRangingModel& rls);
