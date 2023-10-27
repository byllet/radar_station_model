#include "Tracker.hpp"
#include "../math/Calculating.hpp"

#include <vector>

double EPSILON = 1;
double dtime;

Tracker::Tracker() : time{0} {}

void Tracker::TakeRawData(std::vector<Vec3> positions, double dt)
{
    time += dt;
    dtime = dt; 
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

void Tracker::UpdateAim(Aim& aim, Vec3 measured_position) //realization of alpha-beta filter
{
    double k = aim.k++;

    if (k == 1) {
        aim.filtered_position = measured_position;
        return;
    } else if (k == 2) {
        aim.filtered_velocity = (measured_position - aim.filtered_position);
        aim.filtered_velocity = aim.filtered_velocity * (1./ dtime);
        aim.filtered_position = measured_position;

        aim.extrapolated_position = aim.filtered_position + (aim.filtered_velocity * dtime);
        aim.extrapolated_velocity = aim.filtered_velocity;
        return;
    }

    double alpha = 0.52380952380952384;
    double beta = 0.14285714285714285;
    if (k <= 6) {
        alpha = (2.0 * (2.0 * k - 1.0)) / (k * (k + 1.0));
        beta = 6.0 / (k * (k + 1));
    }

    Vec3 pre_calc = measured_position - aim.extrapolated_position;
    aim.filtered_position = aim.extrapolated_position;
    aim.filtered_position += (pre_calc * alpha);

    aim.filtered_velocity = aim.extrapolated_velocity;
    aim.filtered_velocity += (beta / dtime * pre_calc);

    aim.extrapolated_position = aim.filtered_position;
    aim.extrapolated_position += aim.filtered_velocity * dtime;
    aim.extrapolated_velocity = aim.filtered_velocity;
}

void Tracker::HandleRemainsPositions(std::vector<Vec3>& positions)
{
    for (auto position: positions) {
        bool should_create_new = true;
        for (auto aim: aims) {
            if ((position - aim.filtered_position).Length() < EPSILON * 2) {
                should_create_new = false;
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
        if (time - aims[i].update_time > 3) {
            archive.push_back(aims[i]);
            aims.erase(aims.begin() + i);
        }
    }
}
