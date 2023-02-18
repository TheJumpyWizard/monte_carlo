#include <iostream>
#include "monte_carlo.hpp"

int main()
{
    // Set up the Monte Carlo simulation
    MonteCarloSimulator simulator(100, 0.05, 0.20, 1.0/252.0);

    // Run the simulation for 252 days
    for (int i = 0; i < 252; i++) {
        double price = simulator.nextPrice();
        std::cout << "Day " << i+1 << ": " << price << std::endl;
    }

    return 0;
}

