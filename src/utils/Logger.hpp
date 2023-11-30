#pragma once

#include <fstream>

#include "../Manager.hpp"


class Logger {
public:
    Logger(Manager* m);
    void Update();

private:
    Manager* manager;
    std::ofstream logfile;
};