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

    // Part 3
    std::vector<double> square(data.size());
    std::transform(data.begin(), data.end(), square.begin(), [&average](double x) { return std::pow(x - average, 2); });
    double stddev { std::sqrt(std::accumulate(square.begin(), square.end(), 0)) / static_cast<double>(data.size()) };
    std::cout << "stddev : " << stddev << std::endl;

    // Part 4
    auto iter { std::remove_if(data.begin(), data.end(), [&average, &stddev](double x) { return std::abs(x - average) > 2 * stddev; }) };
    data.erase(iter, data.end());

    return 0;
}