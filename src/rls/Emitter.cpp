#include "Emitter.hpp"
#include "../math/Calculating.hpp"

#include <iostream>
#include <cmath>

const double PI = std::acos(-1);

Emitter::Emitter() {}

Emitter::Emitter(Vec3 position) : position{position} {}

std::vector<Signal> Emitter::SendSignals(std::size_t beams_count, Vec3 direction, double solid_angle, double duration)
{
    solid_angle = solid_angle < 4*PI ? solid_angle : 4*PI;

    std::vector<Signal> vec_signals(beams_count);

    double h = 1.;

    int spiral_step = 100; // шаг спирали

    double spiral_coefficient = (h/2*PI*spiral_step) * sqrt(solid_angle/PI) * (1./sqrt(1 - solid_angle/PI)); // коэффициент k в параметрической формуле спирали: x = k*cos(t); y = k*sin(t)

    //std::cout << "MY" << (1./sqrt(1 - solid_angle/PI)) << std::endl;

    double spiral_length = spiral_coefficient*((log(std::abs(sqrt(pow(2*PI*spiral_step,2) + 1) + 2*PI*spiral_step)) + 2*PI*spiral_step*sqrt(pow(2*PI*spiral_step,2) + 1))/2); // длина дуги спирали

    double step_for_points = spiral_length / beams_count; // шаг, с которым точки будут расположены по спирали

    Vec3 init_direction{0., 0., h};

//     std::cout << "coef" << spiral_coefficient << std::endl;
//     std::cout << "len" << spiral_length << std::endl;
//     std::cout << "step" << step_for_points << std::endl;



    // std::cout << (init_direction.x * 0. + init_direction.y * direction.y + init_direction.z * direction.z) << std::endl;
    // std::cout << (init_direction.Length() * sqrt(std::pow(direction.y, 2) + std::pow(direction.z, 2))) << std::endl;



    // std::cout << std::abs(std::acos((init_direction.x * 0. + init_direction.y * direction.y + init_direction.z * direction.z) / (init_direction.Length() * sqrt(std::pow(direction.y, 2) + std::pow(direction.z, 2))))) << std::endl;



    double alpha = (direction.x / std::abs(direction.x)) * std::abs(std::acos((init_direction.x * 0. + init_direction.y * direction.y + init_direction.z * direction.z) / (init_direction.Length() * sqrt(std::pow(direction.y, 2) + std::pow(direction.z, 2)))));
    double beta = (direction.y / std::abs(direction.y)) * std::acos((init_direction.x * direction.x + init_direction.y * 0. + init_direction.z * direction.z) / (init_direction.Length() * sqrt(std::pow(direction.x, 2) + std::pow(direction.z, 2))));
    double gamma = (direction.z / std::abs(direction.z)) * std::acos((init_direction.x * direction.x + init_direction.y * direction.y + init_direction.z * 0.) / (init_direction.Length() * sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2))));

    //std::cout << alpha << ' ' << beta << ' ' << gamma << std::endl;

    double x_coord; // нужны для заполнения телесного угла лучами
    double y_coord; //

    for (std::size_t i = 0; i < beams_count; ++i) // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
    {
        x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
        y_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

        vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, VectorRotation((Vec3{x_coord, y_coord ,1.}).Normalization(), alpha, beta, gamma) + position, SIGNALSPEED, duration);
    }

    return vec_signals;
}
