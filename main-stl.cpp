#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    // Part 1
    std::vector<double> data(100000);
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);
    std::generate_n(data.begin(), data.size(), [&]() { return distribution(generator); });

    // Part 2
    double average { std::accumulate(data.begin(), data.end(), 0.0) / data.size() };
    std::cout << "average : " << average << std::endl;
    

    return 0;
}