#include "Tracker.hpp"
#include <vector>

double EPSILON = 1;

Tracker::Tracker() : time{0} {}

void Tracker::TakeRawData(std::vector<Vec3> positions, double dt)
{
    time += dt;
    HandleExpectedPositions(positions);
    HandleRemainsPositions(positions);
    HandleUntrackedAims();
}

void Tracker::HandleExpectedPositions(std::vector<Vec3>& positions)
{
    std::vector<std::vector<Vec3>> nearest_positions(aims.size());

    for (int j = 0; j < aims.size(); ++j) {
        for (int i = 0; i < positions.size(); ++i) {    
            double delta = (aims[j].GetExpectedPoisiton() - positions[i]).Length();
            if (delta <= EPSILON) {
                nearest_positions[j].push_back(positions[i]);
                positions.erase(positions.begin() + i);
                --i;
            }
        }
    }

    for (unsigned int i = 0; i < aims.size(); ++i) {
        if (!nearest_positions[i].empty()) {
            UpdateAim(aims[i], nearest_positions[i][0]);
        }
    }
}

void Tracker::UpdateAim(Aim& aim, Vec3 new_position)
{
    aim.SetExpectedPosition(new_position);
    aim.SetUpdateTime(time);
}

void Tracker::HandleRemainsPositions(std::vector<Vec3>& positions)
{
    for (auto position: positions) {
        bool should_create = true;
        for (auto aim: aims) {
            if ((position - aim.GetExpectedPoisiton()).Length() < EPSILON * 2) {
                should_create = false;
            }
        }
        if (should_create) {
            CreateNewAim(position);
        }
    }
}

void Tracker::CreateNewAim(Vec3 position) 
{
    Aim new_aim{position, time};
    aims.push_back(new_aim);
}

void Tracker::HandleUntrackedAims()
{
    for (unsigned int i = 0; i < aims.size(); ++i) {
        if (time - aims[i].GetUpdateTime() > 3) {
            aims.erase(aims.begin() + i);
        }
    }
}
