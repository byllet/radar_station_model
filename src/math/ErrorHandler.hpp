#include <vector>
#include <cmath>
#include "../utils/Vec3.hpp"

class ErrorHandler {
public:
    ErrorHandler();
    ErrorHandler(double sigma_0);
    void CalculateAQE(double alpha, double beta);
    void UpdateAverageSigma(double new_sigma_coord, double new_sigma_velocity);
    double GetSigmaCoord();
    double GetSigmaVelocity();
    double GetDeltaCoord(Vec3 real_coord, Vec3 estimated_coord);
    double GetDeltaVelocity(Vec3 real_velocity, Vec3 estimated_velocity);
private:
    size_t dt = 1;
    double K_exstr = 0;
    double K = 0;
    double sigma_0;
    double sigma_coord_prev = 0.0001;
    double sigma_coord_curr;
    double sigma_velocity_prev = 0.0001;
    double sigma_velocity_curr;
    double sigma_exstr_coord;
    double average_sigma_coord;
    double average_sigma_velocity;
};