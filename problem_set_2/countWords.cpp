#include <iostream>
#include <cstring>
using namespace std;

bool containsWord(char word[101], char grid[100][100], unsigned int gridRows, unsigned int gridColumns)
{
	int wordLength = strlen(word);
	for (int i = 0; i < gridRows; i++)
	{
		for (int j = 0; j < gridColumns; j++)
		{
			for (int k = 0; k < wordLength; k++)
			{
				if (word[k] != grid[i][j + k])
				{
					break;
				}
				if (k == wordLength - 1)
				{
					return true;
				}
			}
		}
	}

	for (int i = 0; i < gridColumns; i++)
	{
		for (int j = 0; j < gridRows; j++)
		{
			for (int k = 0; k < wordLength; k++)
			{
				if (word[k] != grid[j + k][i])
				{
					break;
				}
				if (k == wordLength - 1)
				{
					return true;
				}
			}
		}
	}

	return false;
}

unsigned int countWords(char words[50][101], unsigned int numWords, char grid[100][100], unsigned int gridRows, unsigned int gridColumns)
{
	unsigned int wordCount = 0;
	for (int i = 0; i < numWords; i++)
	{
		if (containsWord(words[i], grid, gridRows, gridColumns))
		{
			wordCount++;
		}
	}
	return wordCount;
}

int main()
{
	char grid[100][100] = {
		{'x', 'h', 'e', 'l', 'l', 'o', 'y', 'z'},
		{'z', 't', 'o', 'w', 'o', 'r', 'l', 'd'},
		{'c', 'a', 't', 'r', 'd', 'o', 'g', 's'},
		{'t', 'e', 'h', 'e', 'l', 'l', 'o', 'n'}};
	char words[50][101] = {"hello", "world", "fmi"};
	std::cout << countWords(words, 3, grid, 4, 8) << '\n';

	char words1[50][101] = {"a", "h", "r", "d"};
	char grid1[100][100] = {
		{'a', 'h', 'h', 'r', 'l', 'd'},
		{'a', 'h', 'e', 'r', 'l', 'd'},
		{'a', 'e', 'h', 'r', 'l', 'd'},
		{'a', 'l', 'e', 'r', 'l', 'd'},
		{'a', 'l', 'l', 'r', 'l', 'd'},
		{'a', 'o', 'l', 'r', 'l', 'd'},
		{'a', 'w', 'o', 'r', 'l', 'd'},
	};
	std::cout << countWords(words1, 4, grid1, 7, 6) << '\n';

	return 0;
}