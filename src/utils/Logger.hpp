#pragma once

#include <cmath>
#include <vector>
#include <fstream>

#include "../src/air_models/AbstractAirObject.hpp"

class Manager;

class Logger {
public:
    Logger(Manager* m);
    ~Logger();
    void Update();

private:
    void Write(AbstractAirObject* air_obj, Vec3& predicted);
    Manager* manager;
    std::ofstream logfile_true;
    std::ofstream logfile_predicted;
};
