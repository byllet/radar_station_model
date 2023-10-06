#include "Scene.hpp"
#include "unistd.h"
Scene::Scene()
{
    time = 0;
    radar = Radar(Vec3{0., 0., 0.});
    signal = Signal(Vec3{0.,0.,0.}, Vec3{0., 1., 0.}, 1., 20);
}

Scene::Scene(int time, Radar radar, Signal signal)
{
    this->time = time;
    this->radar = radar;
    this->signal = signal;
}

void Scene::update()
{
    time += 1;
    signal.lifetime += 1;
    if (signal.lifetime <= signal.duration)
    {
        signal.position += signal.direction;
    } else {
        signal.position = Vec3{-1., -1., -1.}
    }
}

void Scene::show(int duration)
{
    
    for (int t = 0; t < duration; ++t)
    {
        std::vector<char> vec = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
        if ((signal.position.y) != -1)
            vec[signal.position.y];
        std::cout << vec << std::endl;
        (*this).update();
        sleep(1);
    }
}