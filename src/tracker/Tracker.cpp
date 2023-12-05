#include "Tracker.hpp"
#include "../math/Calculating.hpp"

#include <vector>

double EPSILON = 10;
const double T0 = 0.033;

Tracker::Tracker() : time{0} {}

void Tracker::TakeRawData(std::vector<Vec3> positions)
{
    time += T0;
    HandleExpectedPositions(positions);
    HandleRemainsPositions(positions);
    HandleUntrackedAims();
}

void Tracker::HandleExpectedPositions(std::vector<Vec3>& positions)
{
    std::vector<std::vector<Vec3>> nearest_positions(aims.size());

    for (int j = aims.size() - 1; j > - 1; --j) {
        for (int i = positions.size() - 1; i > -1; --i) {    
            double delta = (aims[j].filtered_position - positions[i]).Length();
            if (delta <= EPSILON) {
                nearest_positions[j].push_back(positions[i]);
                positions.erase(positions.begin() + i);
            }
        }
    }

    for (size_t i = 0; i < aims.size(); ++i) {
        if (!nearest_positions[i].empty()) {
            Vec3 avg_pos = GetAvg(nearest_positions[i]);
            UpdateAim(aims[i], avg_pos);
        }
    }
}

//realization of alpha-beta filter
void Tracker::UpdateAim(Aim& aim, Vec3 measured_position) 
{
    double k = aim.k++;
    aim.update_time = time;

    //CalculatePosition(aim, measured_position)

    if (k == 1) {
        aim.filtered_position = measured_position;
        return;
    } else if (k == 2) {
        aim.filtered_velocity = (measured_position - aim.filtered_position) / T0;
        aim.filtered_position = measured_position;

        aim.extrapolated_position = aim.filtered_position + (aim.filtered_velocity * T0);
        aim.extrapolated_velocity = aim.filtered_velocity;
        return;
    }

    double alpha = 6.0 / (k * (k + 1));
    double beta = (2.0 * (2.0 * k - 1.0)) / (k * (k + 1.0));

    aim.filtered_position = aim.extrapolated_position + (alpha * (measured_position - aim.extrapolated_position));
    aim.filtered_velocity = aim.extrapolated_velocity + (beta / T0 * (measured_position - aim.extrapolated_position));

    aim.extrapolated_position = aim.filtered_position + (aim.filtered_velocity * T0);
    aim.extrapolated_velocity = aim.filtered_velocity;
}

void Tracker::HandleRemainsPositions(std::vector<Vec3>& positions)
{
    for (auto& position: positions) {
        bool should_create_new = true;
        for (auto& aim: aims) {
            if ((position - aim.filtered_position).Length() < EPSILON) {
                should_create_new = false;
                break;
            }
        }
        if (should_create_new) {
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
    for (size_t i = 0; i < aims.size(); ++i) {
        if (time - aims[i].update_time > T0 * 10) {
            archive.push_back(aims[i]);
            aims.erase(aims.begin() + i);
        }
    }
}

std::vector<Vec3> Tracker::GetAimsPositions()
{
    std::vector<Vec3> positions;
//     for (auto& aim : aims) {
//         positions.push_back(aim.filtered_position);
//     }
    if (!aims.empty()) {
        positions.push_back(aims[0].filtered_position);
    }
    return positions;
}
