#include "../utils/Vec3.hpp"
#include "../rls/Radar.hpp"

class Scene
{
public:
    int time;
    Radar radar;
    Signal signal;

    Scene();
    Scene(int time, Radar radar, Signal signal);
    void update();
    void show(int duration);
};