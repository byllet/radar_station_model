#include "Emitter.hpp"
#include <cmath>
const double PI = 3.14159265359;

Emitter::Emitter() {}

Emitter::Emitter(Vec3 position) : position{position} {}

Vec3 VectorRotation(Vec3 vec, double alpha, double beta, double gamma)
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

    direction.normalize();

    solid_angle = solid_angle < 1.9*PI ? solid_angle : 1.9*PI;

    std::vector<Signal> vec_signals(beams_count);

    double h = 1.;

    int spiral_step = 100; // шаг спирали

    double fi = acos(1. - solid_angle/(2*PI));

    double spiral_coefficient = (h * tan(fi))/(2 * PI * spiral_step); // коэффициент k в параметрической формуле спирали: x = k*cos(t); y = k*sin(t)

    double spiral_length = spiral_coefficient*((log(abs(sqrt(pow(2*PI*spiral_step,2) + 1) + 2*PI*spiral_step)) + 2*PI*spiral_step*sqrt(pow(2*PI*spiral_step,2) + 1))/2); // длина дуги спирали

    double step_for_points = spiral_length / beams_count; // шаг, с которым точки будут расположены по спирали

    if (direction.X() == 0. && direction.Z() == 0.)
    {
        double x_coord = 0.;
        double z_coord = 0.;

        for (size_t i = 0; i < beams_count; ++i) // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
        {
            x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            z_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, Vec3{x_coord, h,  z_coord}.normalize(), SIGNALSPEED, duration);

            return vec_signals;

        }
    } else if (direction.Y() == 0. && direction.Z() == 0.)
    {

        double y_coord = 0.;
        double z_coord = 0.;

        for (size_t i = 0; i < beams_count; ++i) // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
        {
            y_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            z_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, Vec3{h, y_coord,  z_coord}.normalize(), SIGNALSPEED, duration);
        }

        return vec_signals;

    } else
    {

        Vec3 init_direction{0., 0., h};

        double alpha = std::acos((init_direction.X() * 0. + init_direction.Y() * direction.Y() + init_direction.Z() * direction.Z()) / (init_direction.length() * sqrt(std::pow(direction.Y(), 2) + std::pow(direction.Z(), 2))));
        alpha = direction.Y() > 0 ? (2*PI - alpha) : alpha;

        double beta = std::acos((init_direction.X() * direction.X() + init_direction.Y() * 0. + init_direction.Z() * direction.Z()) / (init_direction.length() * sqrt(std::pow(direction.X(), 2) + std::pow(direction.Z(), 2))));
        beta = direction.X() >= 0 ? beta : (2*PI - beta);

        double gamma = 0;

        double x_coord = 0.; // нужны для заполнения телесного угла лучами
        double y_coord = 0.; //

        for (size_t i = 0; i < beams_count; ++i) // строим спираль перпендикулярную плоскости XY в центре СК и затем переносим в местоположение радара
        {
            x_coord = spiral_coefficient * i * step_for_points * std::cos(i * step_for_points);
            y_coord = spiral_coefficient * i * step_for_points * std::sin(i * step_for_points);

            vec_signals[i] = Signal(Vec3{0., 0., 0.} + position, VectorRotation((Vec3{x_coord, y_coord, h}), alpha, beta, gamma).normalize(), SIGNALSPEED, duration);
        }

        return vec_signals;

    }
}