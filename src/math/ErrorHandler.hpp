#include <vector>
#include <cmath>

class ErrorHandler {
public:
    ErrorHandler();
    ErrorHandler(size_t dt, double sigma_0);
    std::vector<double> GetAQE(double alpha, double beta);
    
private:
    size_t dt = 0;
    double sigma_0;
    double sigma_coord_prev;
    double sigma_velocity_prev;
    double sigma_coord_curr;
    double sigma_velocity_curr;
};