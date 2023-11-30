#include <vector>

#include "Logger.hpp"
#include "../air_models/AbstractAirObject.hpp"

Logger::Logger(Manager* m) : manager{m} 
{
    logfile  = std::ofstream("../log.txt");
}

void Logger::Update()
{
    AbstractAirObject* plane;
    if (!manager->GetFlyingObjects().empty()) {
        plane = manager->GetFlyingObjects()[0];
        std::vector<Vec3> v = manager->GetPositionsFromTracker();
        Vec3 aim_pos;
        if (v.empty()) {
            aim_pos = {};
        } else {
            aim_pos = v[0];
        }
        logfile << "[" << plane->GetPosition() << " | " << aim_pos  << "]\n";
    }
}