#include <iostream>
#include <iomanip>
#include "database.hpp"

void Database::UpdateDatabase(int boomCount, double cost)
{
    if (minBoom > boomCount)
    {
        minBoom = boomCount;
    }
    if (maxBoom < boomCount)
    {
        maxBoom = boomCount;
    }
    totalBoom += boomCount;

    if (minCost > cost)
    {
        minCost = cost;
    }
    if (maxCost < cost)
    {
        maxCost = cost;
    }
    totalCost += cost;
    boomData.emplace_back(boomCount);
    mesoCostData.emplace_back(cost);
}

void Database::ShowData(int numTrials)
{
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "BOOMS: " << std::endl;
    std::cout << "   Min: " << minBoom << std::endl;
    std::cout << "   Max: " << maxBoom << std::endl;
    std::cout << "   Avg: " << totalBoom / numTrials << std::endl;

    std::cout << "COST: " << std::endl;
    std::cout << "   Min: " << minCost << std::endl;
    std::cout << "   Max: " << maxCost << std::endl;
    std::cout << "   Avg: " << totalCost / numTrials << std::endl;
}