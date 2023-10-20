#include "RadioDetectionAndRangingModel.hpp"

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel()
{
    position = Vec3{0., 0., 0.};
    emitter = Emitter(Vec3{0.,0.,0.});
    reciever = Reciever(Vec3{0.,0.,0.});
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(Vec3 position, Emitter emitter, Reciever reciever)
{
    this->position = position;
    this->emitter = emitter;
    this->reciever = reciever;
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar)
{
    position = radar.position;
    emitter = radar.emitter;
    reciever = radar.reciever;
}

void RadioDetectionAndRangingModel::Start()
{
    
}

void RadioDetectionAndRangingModel::Update(double dt) {}

