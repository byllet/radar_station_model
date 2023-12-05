#include "Emitter.hpp"
#include "../math/Calculating.hpp"

#include <iostream>
#include <cmath>

const double PI = std::acos(-1);

Emitter::Emitter() {}

Emitter::Emitter(Vec3 position) : position{position} {}

std::vector<Signal> Emitter::SendSignals(std::size_t beams_count, Vec3 direction, double solid_angle, double power)
{

    direction.Normalization();

    solid_angle = solid_angle < 1.9*PI ? solid_angle : 1.9*PI;

    std::vector<Signal> vec_signals(beams_count);

    double h = 1.;

    int spiral_step = 100; // шаг спирали

    double fi = acos(1. - solid_angle/(2*PI));

    double spiral_coefficient = (h * tan(fi))/(2 * PI * spiral_step); // коэффициент k в параметрической формуле спирали: x = k*cos(t); y = k*sin(t)

    double spiral_length = spiral_coefficient*((log(abs(sqrt(pow(2*PI*spiral_step,2) + 1) + 2*PI*spiral_step)) + 2*PI*spiral_step*sqrt(pow(2*PI*spiral_step,2) + 1))/2); // длина дуги спирали

    double step_for_points = spiral_length / beams_count; // шаг, с которым точки будут расположены по спирали

    if (direction.x == 0. && direction.z == 0.) {
        double x_coord = 0.;
        double z_coord = 0.;

        for (size_t i = 0; i < beams_count; ++i) { // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
            x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            z_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, Vec3{x_coord, h,  z_coord}.Normalization(), power/beams_count);

            return vec_signals;

        }
    } else if (direction.y == 0. && direction.z == 0.) {

        double y_coord = 0.;
        double z_coord = 0.;

        for (size_t i = 0; i < beams_count; ++i) { // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
            y_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            z_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, Vec3{h, y_coord,  z_coord}.Normalization(), power/beams_count);
        }

        return vec_signals;

    } else {

        Vec3 init_direction{0., 0., h};

        double alpha = std::acos((init_direction.x * 0. + init_direction.y * direction.y + init_direction.z * direction.z) / (init_direction.Length() * sqrt(std::pow(direction.y, 2) + std::pow(direction.z, 2))));
        alpha = direction.y > 0 ? (2*PI - alpha) : alpha;

        double beta = std::acos((init_direction.x * direction.x + init_direction.y * 0. + init_direction.z * direction.z) / (init_direction.Length() * sqrt(std::pow(direction.x, 2) + std::pow(direction.x, 2))));
        beta = direction.x >= 0 ? beta : (2*PI - beta);

        double gamma = 0;

        double x_coord = 0.; // нужны для заполнения телесного угла лучами
        double y_coord = 0.; //

        for (size_t i = 0; i < beams_count; ++i) {// строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
            x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            y_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, VectorRotation((Vec3{x_coord, y_coord, h}), alpha, beta, gamma).Normalization(), power/beams_count);
        }

        return vec_signals;
    }
}