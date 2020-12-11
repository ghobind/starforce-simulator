#include "equipment.hpp"
#include "utility.hpp"
#include "database.hpp"

int main()
{
    PromptResponse prompt = Prompts();

    // make SF probability table
    std::vector<StarForceChance> table = makeTable(prompt.safeguard, prompt.starcatching);

    // Data collection
    Database db;

    // run simulation for num trials
    for (unsigned i = 0; i < prompt.numTrials; i++)
    {
        std::random_device rd;
        std::mt19937 randGen(rd());
        Equipment equip = Equipment(prompt.level, prompt.currSF, randGen, table);
        double cost = 0;
        while (equip.getCurrentStarForce() != prompt.targetSF)
        {
            cost += equip.MesoCost();
            if (prompt.safeguard)
            {
                int curr = equip.getCurrentStarForce();
                if (curr >= 12 && curr <= 17)
                {
                    // add meso cost for safeguard
                    cost += equip.MesoCost();
                }
            }
            equip.Starforce();
        }
        db.UpdateDatabase(equip.getBoomCount(), cost);
    }
    db.ShowData(prompt.numTrials);
}