#include "Emitter.hpp"
#include <cmath>
const double PI = 3.14159265359;

Emitter::Emitter() {}

Emitter::Emitter(Vec3 position) : position{position} {}

Vec3 Emitter::VectorRotation(Vec3 vec, double alpha, double beta, double gamma)
{
    std::vector <double> vec_matrix = {cos(beta)*cos(gamma),                                     -sin(gamma)*cos(beta),                                     sin(beta),
                                        sin(alpha)*sin(beta)*cos(gamma) + sin(gamma)*cos(alpha), -sin(alpha)*sin(beta)*sin(gamma) + cos(alpha)*cos(gamma), -sin(alpha)*cos(beta),
                                        sin(alpha)*sin(gamma) - sin(beta)*cos(alpha)*cos(gamma), sin(alpha)*cos(gamma) + sin(beta)*sin(gamma)*cos(alpha), cos(alpha)*cos(beta)};
    Matrix matrix(vec_matrix, 3, 3);
    vec = matrix * vec;
    return vec;

}

std::vector<Signal> Emitter::SendSignals(std::size_t beams_count, Vec3 direction, double solid_angle, double duration)
{
    solid_angle = solid_angle < 4*PI ? solid_angle : 4*PI;

    std::vector<Signal> vec_signals(beams_count);

    double h = 1.;

    int spiral_step = 100; // шаг спирали

    double spiral_coefficient = (h/2*PI*spiral_step) * sqrt(solid_angle/PI) * (1./sqrt(1 - solid_angle/PI)); // коэффициент k в параметрической формуле спирали: x = k*cos(t); y = k*sin(t)

    std::cout << "MY" << (1./sqrt(1 - solid_angle/PI)) << std::endl;

    double spiral_length = spiral_coefficient*((log(std::abs(sqrt(pow(2*PI*spiral_step,2) + 1) + 2*PI*spiral_step)) + 2*PI*spiral_step*sqrt(pow(2*PI*spiral_step,2) + 1))/2); // длина дуги спирали

    double step_for_points = spiral_length / beams_count; // шаг, с которым точки будут расположены по спирали

    Vec3 init_direction{0., 0., h};

    std::cout << "coef" << spiral_coefficient << std::endl;
    std::cout << "len" << spiral_length << std::endl;
    std::cout << "step" << step_for_points << std::endl;



    std::cout << (init_direction.X() * 0. + init_direction.Y() * direction.Y() + init_direction.Z() * direction.Z()) << std::endl;
    std::cout << (init_direction.length() * sqrt(std::pow(direction.Y(), 2) + std::pow(direction.Z(), 2))) << std::endl;



    std::cout << std::abs(std::acos((init_direction.X() * 0. + init_direction.Y() * direction.Y() + init_direction.Z() * direction.Z()) / (init_direction.length() * sqrt(std::pow(direction.Y(), 2) + std::pow(direction.Z(), 2))))) << std::endl;



    double alpha = (direction.X() / std::abs(direction.X())) * std::abs(std::acos((init_direction.X() * 0. + init_direction.Y() * direction.Y() + init_direction.Z() * direction.Z()) / (init_direction.length() * sqrt(std::pow(direction.Y(), 2) + std::pow(direction.Z(), 2)))));
    double beta = (direction.Y() / std::abs(direction.Y())) * std::acos((init_direction.X() * direction.X() + init_direction.Y() * 0. + init_direction.Z() * direction.Z()) / (init_direction.length() * sqrt(std::pow(direction.X(), 2) + std::pow(direction.Z(), 2))));
    double gamma = (direction.Z() / std::abs(direction.Z())) * std::acos((init_direction.X() * direction.X() + init_direction.Y() * direction.Y() + init_direction.Z() * 0.) / (init_direction.length() * sqrt(std::pow(direction.X(), 2) + std::pow(direction.Y(), 2))));

    std::cout << alpha << ' ' << beta << ' ' << gamma << std::endl;

    double x_coord; // нужны для заполнения телесного угла лучами
    double y_coord; //

    for (std::size_t i = 0; i < beams_count; ++i) // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
    {
        x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
        y_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

        vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, VectorRotation((Vec3{x_coord, y_coord ,1.}).normalize(), alpha, beta, gamma) + position, SIGNALSPEED, duration);
    }

    return vec_signals;
}