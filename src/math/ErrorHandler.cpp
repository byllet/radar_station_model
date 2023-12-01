#include "ErrorHandler.hpp"

ErrorHandler::ErrorHandler() {}

ErrorHandler::ErrorHandler(double sigma_0)
{
    this->sigma_0 = sigma_0;
    sigma_coord_prev = sigma_0;
    sigma_velocity_prev = (sqrt(2) * sigma_0) / dt;
}

void ErrorHandler::CalculateAQE(double alpha, double beta)
{
    sigma_exstr_coord = sqrt(pow(sigma_coord_prev, 2) + 2 * K * dt + pow(sigma_velocity_prev, 2) * pow(dt ,2));
    K_exstr = K + pow(sigma_velocity_prev, 2) * dt;
    K = ((1 - alpha) * beta * pow(sigma_exstr_coord, 2)) / dt + (1 - alpha) * K_exstr;
    sigma_velocity_curr = sqrt(pow(((beta * sigma_exstr_coord) / dt), 2) - (2 * beta * K_exstr) / dt + pow(sigma_velocity_prev, 2));
    sigma_coord_curr = sqrt(pow((1 - alpha) * sigma_exstr_coord, 2));     
    
    UpdateAverageSigma(sigma_coord_curr, sigma_velocity_curr);
}

void ErrorHandler::UpdateAverageSigma(double new_sigma_coord, double new_sigma_velocity)
{
    average_sigma_coord = ((dt-1) * average_sigma_coord + new_sigma_coord) / dt;
    average_sigma_velocity = ((dt-1) * average_sigma_velocity + new_sigma_velocity) / dt;
}

double ErrorHandler::GetSigmaCoord()
{
    return sigma_coord_curr;
}

double ErrorHandler::GetSigmaVelocity()
{
    return sigma_velocity_curr;
}

double ErrorHandler::GetDeltaCoord(Vec3 real_coord, Vec3 estimated_coord)
{
    return sqrt(pow(real_coord.x - estimated_coord.x, 2) + pow(real_coord.y - estimated_coord.y, 2) + pow(real_coord.z - estimated_coord.z, 2));
}

double ErrorHandler::GetDeltaVelocity(Vec3 real_velocity, Vec3 estimated_velocity)
{
    return sqrt(pow(real_velocity.x - estimated_velocity.x, 2) + pow(real_velocity.y - estimated_velocity.y, 2) + pow(real_velocity.z - estimated_velocity.z, 2));
}