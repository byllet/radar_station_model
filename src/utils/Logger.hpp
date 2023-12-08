#pragma once

#include <fstream>

#include "../air_models/AbstractAirObject.hpp"

class Manager;

class Logger {
public:
    Logger(Manager* m);
    void Update();

private:
    void Write(AbstractAirObject* air_obj, Vec3& predicted);
    Manager* manager;
    std::ofstream logfile_true;
    std::ofstream logfile_predicted;
};