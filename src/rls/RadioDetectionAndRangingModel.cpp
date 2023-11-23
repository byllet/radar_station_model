#include "RadioDetectionAndRangingModel.hpp"

const double PI = 3.14159265359;
const double DURATION = 30.;

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel()
{
    position = Vec3{0., 0., 0.};
    emitter = Emitter(Vec3{0.,0.,0.});
    reciever = Reciever(Vec3{0.,0.,0.});
    power = 1000.;
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(Vec3 position, double power)
{
    this->position = position;
    this->emitter = Emitter(position);
    this->reciever = Reciever(position);
    this->power = power;
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar)
{
    position = radar.position;
    emitter = radar.emitter;
    reciever = radar.reciever;
    power = radar.power;
}

std::vector<Signal> RadioDetectionAndRangingModel::Start(size_t beams)
{
    return emitter.SendSignals(beams, Vec3{1., 1., 1.}, PI * 1.5, power);
}

std::vector<Signal> RadioDetectionAndRangingModel::Update(double dt)
{
    return emitter.SendSignals(1000, Vec3{1., 1., 1.}, 1.5 * PI, power);
}

Reciever& RadioDetectionAndRangingModel::GetReciever()
{
    return reciever;
}

Emitter& RadioDetectionAndRangingModel::GetEmitter()
{
    return emitter;
}

Vec3 RadioDetectionAndRangingModel::GetPosition()
{
    return position;
}
