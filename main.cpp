#include <iostream>
#include "src/modeling/Scene.hpp"

int main()
{
    int time = 0;
    RadioDetectionAndRangingModel radar(Vec3{0., 0., 0.});
    Signal signal(Vec3{0.,0.,0.}, Vec3{0., 1., 0.}, 1., 20);

    Scene scene(time, radar, signal);

    scene.create_barrier(Vec3{0., 15., 0.});

    scene.show(25);
}