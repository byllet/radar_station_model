#include "ErrorHandler.hpp"

ErrorHandler::ErrorHandler() {}

ErrorHandler::ErrorHandler(size_t dt, double sigma_0)
{
    this->sigma_0 = sigma_0;
    sigma_coord_prev = sigma_0;
    sigma_velocity_prev = (sqrt(2) * sigma_0) / dt;
}

std::vector<double> ErrorHandler::GetAQE(double alpha, double beta)
{
    
}