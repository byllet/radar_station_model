#include "Scene.hpp"

int main()
{
    int time = 0;
    Radar radar(Vec3{0., 0., 0.});
    Signal signal(Vec3{0.,0.,0.}, Vec3{0., 1., 0.}, 1., 20);

    Scene scene(timr, radar, signal);

    Scene.show(30);

}