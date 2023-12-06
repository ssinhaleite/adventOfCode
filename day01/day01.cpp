#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::ifstream inputFile;
	inputFile.open("adventofcode.com_2023_day_1_input.txt");

	std::string line;
	int firstNumber;
	int lastNumber;

	int sum = 0;
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			// walk for every char from begin to end and check if there is any number in digit
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
					firstNumber = (line[i] - '0');
					break;
				}
			}

			// walk for every char from end to begin and check if there is any number in digit
			for (int i = line.size() - 1; i >= 0; i--) {
				if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
					lastNumber = (line[i] - '0');
					break;
				}
			}
			sum += firstNumber * 10 + lastNumber;
		}
	}

	printf("%d\n", sum);

	return 0;
}
