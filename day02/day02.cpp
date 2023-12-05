#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

// max per color: 12 red cubes, 13 green cubes, and 14 blue cubes
#define MAX_RED_CUBES 12
#define MAX_GREEN_CUBES 13
#define MAX_BLUE_CUBES 14

int main()
{

    std::ifstream input;
    input.open("input.txt");

    std::string line;
    int sum = 0;

    while (std::getline(input, line))
    {
        // line always starts with "Game " remove it from line
        line.erase(0, 5);

        // get the number of the game
        std::string delimiter = ":";
        std::string gameId = line.substr(0, line.find(delimiter));

        // remove the number of the game + : from line
        line.erase(0, gameId.size() + 1);

        std::vector<std::string> rounds;
        while (line.size() > 0)
        {
            delimiter = ";";
            std::string round = line.substr(0, line.find(delimiter));
            rounds.push_back(round);

            // remove round information + ;
            line.erase(0, round.size() + 1);
        }

        bool gameOK = true;
        for (unsigned int i = 0; i < rounds.size(); i++)
        {
            while (rounds[i].size() > 0)
            {
                std::stringstream ss;
                ss << rounds[i];

                std::string color;
                int cubes;

                ss >> cubes;
                ss >> color;

                if (color[color.size()-1] == ',')
                {
                    color.erase(color.size() - 1, 1);
                }

                if ((color == "red" && cubes > MAX_RED_CUBES) || (color == "green" && cubes > MAX_GREEN_CUBES) || (color == "blue" && cubes > MAX_BLUE_CUBES))
                {
                    gameOK = false;
                    break;
                }

                delimiter = ",";
                int position = rounds[i].find(delimiter);
                if (position >= 0)
                {
                    rounds[i].erase(0, position + 1);
                }
                else
                {
                    rounds[i].clear();
                }
            }

            if (!gameOK)
            {
                break;
            }
        }

        if (gameOK)
        {
            sum += std::stoi(gameId);
        }
    }

    input.close();
    std::cout << "answer: " << sum << std::endl;

    return 0;
}
