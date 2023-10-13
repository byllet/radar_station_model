#include "RadioDetectionAndRangingModel.hpp"

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel() : position{Vec3{0., 0., 0.}} {}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(Vec3 position) : position{position} {}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar)
{
    position = radar.position;
}

void RadioDetectionAndRangingModel::Start() {}

void RadioDetectionAndRangingModel::Update(double dt) {}

