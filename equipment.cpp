#include "equipment.hpp"
#include <cmath>

Equipment::Equipment(int level, int starforce, std::mt19937 randGen, std::vector<StarForceChance> table)
    : currStarforce(starforce), level(level), randGen(randGen), table(table)
{
}

double Equipment::MesoCost() const
{
    if (currStarforce >= 0 && currStarforce <= 9)
    {
        return 1000 + (pow(level, 3)) * (currStarforce + 1) / 25;
    }
    else if (currStarforce >= 10 && currStarforce <= 14)
    {
        return 1000 + (pow(level, 3)) * pow((currStarforce + 1), 2.7) / 400;
    }
    else if (currStarforce >= 15 && currStarforce <= 17)
    {
        return 1000 + (pow(level, 3)) * pow((currStarforce + 1), 2.7) / 120;
    }
    else if (currStarforce >= 18 && currStarforce <= 19)
    {
        return 1000 + (pow(level, 3)) * pow((currStarforce + 1), 2.7) / 110;
    }
    else if (currStarforce >= 20 && currStarforce <= 24)
    {
        return 1000 + (pow(level, 3)) * pow((currStarforce + 1), 2.7) / 100;
    }
    return -1;
}

void Equipment::Starforce()
{
    // create random value
    std::uniform_real_distribution<double> dist(0, 1);
    double rand = dist(randGen);
    StarForceChance chance = table[currStarforce];
    if (rand <= chance.success)
    {
        // we succeeded
        currStarforce++;
    }
    else
    {
        // we failed, now check if item destroyed or not
        double probKeep = chance.success + chance.fail;
        if (rand <= probKeep)
        {
            // we keep
            if (currStarforce <= 10 || currStarforce == 15 || currStarforce == 20)
            {
                // will not drop SF
            }
            else
            {
                // will drop SF
                currStarforce--;
            }
        }
        else
        {
            // boom
            currStarforce = 12;
            boomCount++;
        }
    }
}