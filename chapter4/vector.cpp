//
// Created by pepsisme on 19/03/22.
//

#include "iostream"
#include "vector"
#include "algorithm"

int main() {
    std::vector<double> temps;
    for (double temp; std::cin>>temp;) {
        temps.push_back(temp);
    }

    //mean
    double sum = 0;
    for (double x : temps) sum += x;
    std::cout << "Average temp: " <<sum/temps.size() << "\n";

    // median
    std::sort(temps.begin(), temps.end());
    std::cout << "Median temp: " << temps[temps.size()/2] << "\n";

    return 0;
}

