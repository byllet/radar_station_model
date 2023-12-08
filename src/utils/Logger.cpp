#include <cmath>
#include <fstream>
#include <vector>

#include "Logger.hpp"
#include "../air_models/AbstractAirObject.hpp"
#include "../Manager.hpp"

Logger::Logger(Manager* m) : manager{m} 
{
    logfile_true  = std::ofstream("../log_true.txt");
    logfile_predicted  = std::ofstream("../log_predicted.txt");
}

void Logger::Update()
{
    std::vector<AbstractAirObject*> planes = manager->GetFlyingObjects();
    std::vector<Vec3> positions = manager->GetPositionsFromTracker();
    if (planes.empty()) {
        logfile_true << "-\n";
    } else {
        for (auto& plane : planes) {
            logfile_true << "[" << plane->GetPosition() << "]     ";
        }
        logfile_true << '\n';
    }
    
    if (positions.empty()) {
        logfile_predicted << "-\n";
    } else {
        for (auto& pos: positions) {
            logfile_predicted << "[" << pos << "]     ";
        }
        logfile_predicted << '\n';
    } 
}

void  Write(Vec3& position, std::ofstream& stream)
{
}