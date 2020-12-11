#pragma once
#include <random>
#include <vector>

struct StarForceChance
{
    double success;
    double fail;
    double destroy;
};

class Equipment
{
public:
    Equipment(int level, int starforce, std::mt19937 randGen, std::vector<StarForceChance> table);
    int getCurrentStarForce() const { return currStarforce; }
    int getBoomCount() const { return boomCount; }
    double MesoCost() const;
    void Starforce();

private:
    int currStarforce;
    int level;
    int boomCount = 0;
    std::mt19937 randGen;
    std::vector<StarForceChance> table;
};