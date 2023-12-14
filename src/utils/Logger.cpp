#include "../src/utils/Logger.hpp"
#include "../src/air_models/AbstractAirObject.hpp"
#include "../src/Manager.hpp"

Logger::Logger(Manager* m) : manager{m} 
{
    logfile_true.open("/Users/kirill/Desktop/radar_project/code/log_true.txt");
    logfile_predicted.open("/Users/kirill/Desktop/radar_project/code/log_predicted.txt");
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

Logger::~Logger()
{
    logfile_true.close();
    logfile_predicted.close();
}
