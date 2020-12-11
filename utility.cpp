#include <iostream>
#include "utility.hpp"
#include "equipment.hpp"

std::vector<StarForceChance> makeTable(bool safeguard, bool starcatching)
{
    std::vector<StarForceChance> table;
    for (unsigned int i = 0; i < 25; i++)
    {
        double success = 0;
        if (i <= 21)
        {
            int cnt = i;
            if (i >= 3)
            {
                cnt -= 1;
            }
            success = 0.95 - 0.05 * cnt;
            if (success < 0.3)
            {
                success = 0.3;
            }
        }
        else if (i == 22)
        {
            success = .03;
        }
        else if (i == 23)
        {
            success = .02;
        }
        else if (i == 24)
        {
            success = .01;
        }

        if (starcatching)
        {
            success += success * 0.045;
        }

        double fail = 1;
        double destroy = 0;
        fail = 1 - success;
        if (i >= 12 && i <= 17 && !safeguard)
        {
            if (i == 12)
            {
                destroy = 0.01 * fail;
                fail = 0.99 * fail;
            }
            else if (i == 13 || i == 14)
            {
                destroy = 0.02 * fail;
                fail = 0.98 * fail;
            }
            else if (i == 15 || i == 16 || i == 17)
            {
                destroy = 0.03 * fail;
                fail = 0.97 * fail;
            }
        }
        else if (i >= 18)
        {
            if (i == 18 || i == 19)
            {
                destroy = 0.04 * fail;
                fail = 0.96 * fail;
            }
            else if (i == 20 || i == 21)
            {
                destroy = 0.1 * fail;
                fail = 0.9 * fail;
            }
            else if (i == 22)
            {
                destroy = 0.2 * fail;
                fail = 0.8 * fail;
            }
            else if (i == 23)
            {
                destroy = 0.3 * fail;
                fail = 0.7 * fail;
            }
            else if (i == 24)
            {
                destroy = 0.4 * fail;
                fail = 0.6 * fail;
            }
        }
        table.emplace_back(StarForceChance{success, fail, destroy});
    }
    return table;
}

PromptResponse Prompts()
{
    PromptResponse prompt;
    // ask for equip level
    std::cout << "Please enter the level of the equipment: ";
    std::cin >> prompt.level;
    std::cout << std::endl;

    // ask for star catching
    prompt.starcatching = false;
    char response = 'n';
    std::cout << "Would you like starcatching?(y/n): ";
    std::cin >> response;
    std::cout << std::endl;
    if (response == 'y')
    {
        prompt.starcatching = true;
    }

    // ask for safeguard
    prompt.safeguard = false;
    response = 'n';
    std::cout << "Would you like safeguard?(y/n): ";
    std::cin >> response;
    std::cout << std::endl;
    if (response == 'y')
    {
        prompt.safeguard = true;
    }

    // ask for current SF
    std::cout << "Please enter the current starforce value: ";
    std::cin >> prompt.currSF;
    std::cout << std::endl;

    // ask for target SF
    std::cout << "Please enter the desired starforce value: ";
    std::cin >> prompt.targetSF;
    std::cout << std::endl;

    // Ask user for num trials
    std::cout << "Please enter number of simulations to run: ";
    std::cin >> prompt.numTrials;
    std::cout << std::endl;

    return prompt;
}