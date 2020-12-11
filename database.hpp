#pragma once
#include <vector>

class Database
{
public:
    int getMinBoom() const { return minBoom; }
    int getMaxBoom() const { return maxBoom; }
    int getTotalBoom() const { return totalBoom; }
    double getMinCost() const { return minCost; }
    double getMaxCost() const { return maxCost; }
    double getTotalCost() const { return totalCost; }
    void UpdateDatabase(int boomCount, double cost);
    void ShowData(int numTrials);

private:
    std::vector<int> boomData;
    int minBoom = INT_MAX;
    int maxBoom = -1;
    int totalBoom = 0;
    std::vector<double> mesoCostData;
    double minCost = INT_MAX;
    double maxCost = -1;
    double totalCost = 0;
};