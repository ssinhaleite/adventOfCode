#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <math.h> 

int main() {

	std::ifstream input;
	input.open("input.txt");

	std::string line;
	int sum = 0;

	while (std::getline(input, line)) {
		// line always starts with "Card X: " remove it from line
		std::string delimiter = ":";
		std::string position = line.substr(0, line.find(delimiter));
		line.erase(0, position.size() + 1);

		delimiter = "|";
		std::string numbers = line.substr(0, line.find(delimiter));
		line.erase(0, numbers.size() + 1);

		std::set<int> winnerNumbers;
		std::string number = "";
		for (unsigned int i = 0; i <= numbers.size(); i++) {
			if (numbers[i] == ' ') {
				if (number.size() > 0) {
					int winnerNumber = std::stoi(number);
					winnerNumbers.insert(winnerNumber);
					number.clear();
				}
			} else {
				number += numbers[i];
			}
		}

		int numbersFound = 0;
		number = "";
		for (unsigned int i = 0; i <= line.size(); i++) {
			if (line[i] == ' ') {
				if (number.size() > 0) {
					int myNumber = std::stoi(number);
					if (winnerNumbers.find(myNumber) != winnerNumbers.end()) {
						numbersFound++;
						number.clear();
					} else {
						number.clear();
					}
				}
			} else {
				number += line[i];
			}
		}

		if (numbersFound != 0) {
			sum += pow(2, numbersFound - 1);
		}
	}

	input.close();
	std::cout << "answer: " << sum << std::endl;

	return 0;
}
