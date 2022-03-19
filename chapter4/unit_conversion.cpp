#include "iostream"
#include "float.h"
#include "vector"
#include "algorithm"

// declare comparator
static bool sort_using_greater_than(double u, double v);

int main() {
    // const expressions
    constexpr double inch_to_cm = 2.54;
    constexpr double cm_to_m = 1.0/100; // must make top double or integer division is used
    constexpr double feet_to_inch = 12;

    // output variables
    double min = DBL_MAX;
    double max = -DBL_MAX;
    double sum = 0;
    std::vector<double> meter_vector; // vector for storing meters

    // while loop control variables
    double value_meters = 0;
    std::string unit = "";
    bool illegal = false;

    // while valid input
    while (std::cin >> value_meters >> unit) {
        if (unit == "cm") value_meters *= cm_to_m;
        else if (unit == "m") value_meters *= 1;
        else if (unit == "in") value_meters *= inch_to_cm * cm_to_m;
        else if (unit == "ft") value_meters *=  feet_to_inch * inch_to_cm * cm_to_m;
        else {
            illegal = true;
            std::cout << "Illegal measurement\n";
        }

        if (!illegal) {
            // calc max, min, sum
            sum += value_meters;
            if (value_meters > max) max = value_meters;
            if (value_meters < min) min = value_meters;

            meter_vector.push_back(value_meters);
        }
        illegal = false;
    }
    
    // print calculated info
    std::cout << "Max: " << max << " Min: " << min << " Sum: " << sum << "\n";

    // sort meter_vector and print
    std::sort(meter_vector.begin(), meter_vector.end(), sort_using_greater_than);
    for (double x : meter_vector) std::cout << x << " ";
    std::cout << "\n";
}

// comparator implementation
static bool sort_using_greater_than(double u, double v) {
    return u < v;
}

