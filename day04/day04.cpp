#include <math.h>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main() {

	std::ifstream input;
	input.open("input.txt");

	std::string line;
	int result = 0;

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
		if (number.size() != 0) {
			int myNumber = std::stoi(number);
			if (winnerNumbers.find(myNumber) != winnerNumbers.end()) {
				numbersFound++;
			}
		}

		// last number
		if (numbersFound != 0) {
			result += pow(2, numbersFound - 1);
		}
	}

	std::cout << "answer: " << result << std::endl;
	input.close();

	return 0;
}
