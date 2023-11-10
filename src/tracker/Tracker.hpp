#pragma once

#include <unordered_map>
#include <vector>

#include "Aim.hpp"

class Tracker {
public:
    Tracker();
    void TakeRawData(std::vector<Vec3> positions);
    
private:
    std::vector<Aim> aims;
    std::vector<Aim> archive;
    double time;
    void HandleExpectedPositions(std::vector<Vec3>& positions);
    void HandleRemainsPositions(std::vector<Vec3>& positions);
    void UpdateAim(Aim& aim, Vec3 new_position);
    void CreateNewAim(Vec3 position);
    void HandleUntrackedAims();
};
