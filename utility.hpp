#pragma once

#include <vector>
#include "equipment.hpp"

struct PromptResponse
{
    int level;
    bool starcatching;
    bool safeguard;
    int currSF;
    int targetSF;
    unsigned numTrials;
};

std::vector<StarForceChance> makeTable(bool safeguard, bool starcatching);

PromptResponse Prompts();