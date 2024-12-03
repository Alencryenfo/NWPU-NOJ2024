#include <iostream>

using namespace std;

struct PIDController {
    double Kp = 0, Ki = 0, Kd = 0;
    double preError = 0, integral = 0;
} PIDData;

double setpoint, measuredValue;
int n;

int main() {
    cin >> PIDData.Kp >> PIDData.Ki >> PIDData.Kd >> setpoint >> measuredValue >> n;
    for (int i = 1; i <= n; i++) {
        double error = setpoint - measuredValue;
        PIDData.integral += error;
        double dx = error - PIDData.preError, output =
                output + PIDData.Kp * error + PIDData.integral * PIDData.Ki + PIDData.Kd * dx;
        printf("%d %.6lf\n", i, output);
        PIDData.preError = error;
        measuredValue = output;
    }
    return 0;
}
