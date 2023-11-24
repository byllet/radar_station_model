#pragma once

#include "Emitter.hpp"
#include "Reciever.hpp"
#include "../utils/Vec3.hpp"

#include <vector>

class RadioDetectionAndRangingModel {
public:
    RadioDetectionAndRangingModel();
    RadioDetectionAndRangingModel(Vec3 position, double power);
    RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar);

    std::vector<Signal> Start(size_t beams);
    void Update(double dt, std::vector<Signal>& signal_vec);

    Reciever& GetReciever();
    Emitter& GetEmitter();
    Vec3 GetPosition();

    void SetDeparturePeriod(double time);

private:
    Vec3 position;
    Emitter emitter;
    Reciever reciever;
    double power;
    double departure_period = 3.;
    double time = 0;
};
