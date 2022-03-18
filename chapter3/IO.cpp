//
// Created by pepsisme on 19/03/22.
//

# include "iostream"
#include "math.h"

bool repeated_word(void);


int main() {
    std::cout << "Please enter your name and age:\n";

    std::string name;
    double age;

    std::cin >> name;
    std::cin >> age;

    std::cout << "Hello, " << name << ", aged: " << age * 12 << " months, your age square rooted is:" << sqrt(age) << "\n";

    if (repeated_word()) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
}

bool repeated_word() {
    std::string previous = "";
    std::string current;

    std::cout << "Please enter string to check for repeated words:\n";

    while (std::cin>>current) {
        if (previous == current) {
            std::cout << "repeated word: " << current << "\n";
            return true;
        }
        previous = current;
    }
    return false;
}


