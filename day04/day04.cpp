#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <math.h> 

int main()
{

    std::ifstream input;
    input.open("input2.txt");

    std::string line;
    int sum = 0;

    while (std::getline(input, line))
    {
        // line always starts with "Card X: " remove it from line
        std::string delimiter = ":";
        std::string position = line.substr(0, line.find(delimiter));
        line.erase(0, position.size() + 1);

        std::cout << line;

        delimiter = "|";
        std::string numbers = line.substr(0, line.find(delimiter));
        line.erase(0, numbers.size() + 1);
        
        std::stringstream ss;
        ss << numbers;

        std::set<int> winnerNumbers;
        while (ss.tellp() == std::streampos(0))
        {
            int winnerNumber;
            ss >> winnerNumber;
            std::cout << winnerNumber << std::endl;
            winnerNumbers.insert(winnerNumber);
        }

        ss << line;

        int numbersFound = 0;

        while (ss.tellp() == std::streampos(0))
        {
            int number;
            ss >> number;
            std::cout << number << std::endl;

            if(winnerNumbers.find(number) != winnerNumbers.end())
            {
                numbersFound++;
            }
        }

        sum += pow(2, numbersFound - 1);

    }

    input.close();
    std::cout << "answer: " << sum << std::endl;

    return 0;
}
