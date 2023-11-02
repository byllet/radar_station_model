#include "RadioDetectionAndRangingModel.hpp"
const double PI = 3.14159265359;
const double DURATION = 30.;

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel()
{
    position = Vec3{0., 0., 0.};
    emitter = Emitter(Vec3{0.,0.,0.});
    reciever = Reciever(Vec3{0.,0.,0.});
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(Vec3 position)
{
    this->position = position;
    this->emitter = Emitter(position);
    this->reciever = Reciever(position);
    this->detector = CollisionDetector(100.);
}

RadioDetectionAndRangingModel::RadioDetectionAndRangingModel(RadioDetectionAndRangingModel& radar)
{
    position = radar.position;
    emitter = radar.emitter;
    reciever = radar.reciever;
}

void RadioDetectionAndRangingModel::Start()
{
    std::vector<Signal> vec_signals;
    vec_signals = emitter.SendSignals(1000, Vec3{1.,1.,1.}, PI/2, DURATION);
    vec_vec.push_back(vec_signals);
}

void RadioDetectionAndRangingModel::Update(double dt) 
{
    for (auto vec : vec_vec)
        for (auto signal : vec)
        {
            signal.lifetime += dt;
            if (signal.lifetime <= signal.duration)
                signal.position += signal.direction;
            else
                signal.alive = false;
            detector.CheckCollision(signal, plane);
        }
}

