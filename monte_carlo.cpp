#include <iostream>
#include <random>
#include <vector>
#include <cmath>

using namespace std;

vector<double> simulate_price_path(double S0, double r, double sigma, double T, int N) {
    // Calculate the time step
    double dt = T / N;

    // Create a random number generator with mean 0 and standard deviation 1
    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);

    // Generate a set of normally distributed random numbers
    vector<double> Z;
    for (int i = 0; i < N; i++) {
        Z.push_back(distribution(generator));
    }

    // Calculate the price path using geometric Brownian motion
    vector<double> S;
    S.push_back(S0);
    for (int i = 1; i <= N; i++) {
        double St = S[i-1] * exp((r - 0.5 * sigma*sigma) * dt + sigma * sqrt(dt) * Z[i-1]);
        S.push_back(St);
    }

    return S;
}

vector< vector<double> > simulate_price_paths(double S0, double r, double sigma, double T, int N, int M) {
    // Simulate M price paths
    vector< vector<double> > paths;
    for (int i = 0; i < M; i++) {
        vector<double> path = simulate_price_path(S0, r, sigma, T, N);
        paths.push_back(path);
    }

    return paths;
}

int main() {
    double S0 = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    int N = 252;
    int M = 1000;

    vector< vector<double> > paths = simulate_price_paths(S0, r, sigma, T, N, M);

    // Print the first and last price in each path
    for (int i = 0; i < M; i++) {
        cout << "Path " << i+1 << ": " << paths[i][0] << ", " << paths[i][N] << endl;
    }

    return 0;
}

