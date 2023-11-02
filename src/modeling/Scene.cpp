#include "Scene.hpp"
#include "unistd.h"
#include <iostream>

Scene::Scene()
{
    time = 0;
    radar = RadioDetectionAndRangingModel(Vec3{0., 0., 0.});
    signal = Signal(Vec3{0.,0.,0.}, Vec3{0., 1., 0.}, 1., 20);
}

Scene::Scene(int time, RadioDetectionAndRangingModel radar, Signal signal)
{
    this->time = time;
    this->radar = radar;
    this->signal = signal;
}

void Scene::update()
{
    ++time;
    signal.lifetime += 1;
    if (signal.alive)
    {
        if (signal.lifetime <= signal.duration)
        {
            signal.position += signal.direction;
        } else {
            signal.alive = false;
        }
    }
    collision();
}    

void Scene::collision()
{
    if (signal.position == barrier)
    {
        signal.Reflection();
        signal.position += signal.direction;
    }
}

void Scene::create_barrier(const Vec3& vec)
{
    barrier = vec;
}

void Scene::show(int duration)
{
    
    for (int t = 0; t < duration; ++t)
    {

        std::vector<char> vec = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ', ' ', ' '};
        vec[barrier.y] = '|';
        if (signal.alive)
            vec[signal.position.y] = '-';
        std::cout << vec << std::endl;
        (*this).update();
        sleep(1);
    }
}