#include <iostream>
#include <vector>

// 1 milimeter per milisecond
// every milisecond less in the race means an increase in the speed

int main() {

	// particularly, this time the input set is quite small
	// won't do reading/processing of input
	std::vector<int> time = { 53, 83, 72, 88 };
	std::vector<int> distances = { 333, 1635, 1289, 1532 };

	int result = 1;

	// for every round
	for (unsigned int i = 0; i < time.size(); i++)
	{
		int partialResult = 0;
		// for every possible milisecond
		for (unsigned int j = 0; j < time[i]; j++)
		{
			int distance = (time[i] - j) * (1 * j);

			if (distance > distances[i])
			{
				partialResult++;
			}
		}

		result *= partialResult;
	}

	std::cout << "answer: " << result << std::endl;
	return 0;
}
