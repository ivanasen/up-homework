#include <iostream>
#include <cmath>

using namespace std;

unsigned int getNumberLength(int number)
{
	int length = 0;
	do
	{
		length++;
		number /= 10;
	} while (number);

	return length;
}

bool isRepeating(unsigned int number, unsigned int part)
{
	unsigned int partLength = getNumberLength(part);

	while (number)
	{
		int tempPart = part;
		for (int i = 0; i < partLength; i++)
		{
			int lastDigitNumber = number % 10;
			int lastDigitPart = tempPart % 10;
			if (lastDigitNumber != lastDigitPart)
			{
				return false;
			}
			number /= 10;
			tempPart /= 10;
		}
	}

	return true;
}

bool allRepeatedNumbers(unsigned int numbers[], unsigned int length)
{
	for (int i = 0; i < length; i++)
	{
		if (!isRepeating(numbers[i], i))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned int numbers1[] = {0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 101010, 1111};
	unsigned int numbers2[] = {0, 2};
	unsigned int numbers3[] = {0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 10101};

	std::cout << allRepeatedNumbers(numbers1, 12);
	std::cout << allRepeatedNumbers(numbers2, 12);
	std::cout << allRepeatedNumbers(numbers3, 12);
	return 0;
}