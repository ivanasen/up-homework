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

	char words2[50][101] = {"good", "time", "win", "lose"};
    char grid2[100][100] = {
        {'a', 't', 'c', 'g', 'b'},
        {'a', 't', 't', 'o', 'l'},
        {'w', 't', 'i', 'g', 'o'},
        {'w', 't', 'm', 'o', 's'},
        {'i', 't', 'e', 'o', 'b'},
        {'n', 't', 'e', 'd', 'b'}
 
    };
    std::cout << (countWords(words2, 4, grid2, 6, 5) == 3);

	char words3[50][101] = {"knife", "luck", "universe", "paper"};
    char grid3[100][100] = {
        {'s', 'p', 'q', 'p', 'b', 'x', 'b', 's', 'm', 't'},
        {'i', 'k', 'z', 'q', 'm', 'g', 'i', 'g', 'f', 'f'},
        {'e', 't', 'u', 'v', 'i', 'e', 'p', 'u', 'e', 'm'},
        {'h', 'm', 'l', 'k', 's', 'g', 'a', 'w', 'e', 'a'},
        {'c', 'a', 'l', 'u', 'q', 'u', 'p', 'c', 'b', 'l'},
        {'e', 'j', 'u', 'n', 'i', 'v', 'e', 'r', 's', 'e'},
        {'t', 'v', 'c', 'u', 'j', 'z', 'r', 'm', 's', 'n'},
        {'n', 'm', 'k', 'n', 'i', 'f', 'e', 'c', 'a', 'b'},
        {'e', 'f', 'y', 'e', 'r', 'q', 'l', 'o', 'i', 't'},
        {'b', 'l', 'u', 't', 's', 'l', 'z', 'd', 'h', 'f'},
 
    };
    std::cout << (countWords(words3, 4, grid3, 10, 10) == 4);

	char grid4[100][100] = {
        {'g', 'o', 'h', 'd', 'n', 'c', 'o'},
        {'g', 'v', 'w', 'a', 'q', 'a', 'f'},
        {'f', 'c', 'a', 'r', 'u', 'r', 'h'},
        {'y', 'c', 'a', 'r', 'p', 'e', 't'},
        {'e', 'e', 'b', 'f', 'v', 'f', 'y'},
        {'m', 'l', 'o', 't', 'g', 'h', 'y'},
        {'e', 'y', 'e', 'b', 'a', 'l', 'l'}
    };
 
    char words4[50][101] = {"car", "carpet", "care", "eye", "ball", "eyeball"};
 
    std::cout << (countWords(words4, 6, grid4, 7, 7) == 6);

	return 0;
}