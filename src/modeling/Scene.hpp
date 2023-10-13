#include "../utils/Vec3.hpp"
#include "../rls/RadioDetectionAndRangingModel.hpp"

class Scene
{
public:
    int time;
    RadioDetectionAndRangingModel radar;
    Signal signal;
    Vec3 barrier;

    Scene();
    Scene(int time, RadioDetectionAndRangingModel radar, Signal signal);
    void update();
    void show(int duration);
    void create_barrier(const Vec3& vec );
    void collision();
};