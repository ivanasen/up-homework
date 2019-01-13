#include <iostream>
#include <cstring>

using namespace std;

char **getSentenceWords(char sentence[90901], char wordsBuffer[909][101], int &wordCount)
{
	int sentenceLength = strlen(sentence);
	int arrayRow = 0;
	int arrayCol = 0;
	for (int i = 0; i < sentenceLength; i++)
	{
		if (sentence[i] != ' ')
		{
			wordsBuffer[arrayRow][arrayCol++] = sentence[i];
		}
		else
		{
			if (i > 0 && sentence[i - 1] != '\0')
			{
				wordCount++;
			}

			arrayRow++;
			arrayCol = 0;
		}
	}
}

int countReadsRecoursive(char grid[30][30][101],
						 int gridRows,
						 int gridColumns,
						 char words[909][101],
						 int wordCount,
						 int gridRow,
						 int gridColumn,
						 int currentWordIndex = 0)
{
	if (currentWordIndex == wordCount - 1)
	{
		return 1;
	}

	int readCount = 0;
	currentWordIndex++;

	// Go up
	if (gridRow > 0 && (strcmp(words[currentWordIndex], grid[gridRow - 1][gridColumn]) == 0))
	{
		readCount += countReadsRecoursive(grid, gridRows, gridColumns, words, wordCount, gridRow - 1, gridColumn, currentWordIndex);
	}

	// Go right
	if (gridColumn < gridColumns && (strcmp(words[currentWordIndex], grid[gridRow][gridColumn + 1]) == 0))
	{
		readCount += countReadsRecoursive(grid, gridRows, gridColumns, words, wordCount, gridRow, gridColumn + 1, currentWordIndex);
	}

	// Go down
	if (gridRow < gridRows && (strcmp(words[currentWordIndex], grid[gridRow + 1][gridColumn]) == 0))
	{
		readCount += countReadsRecoursive(grid, gridRows, gridColumns, words, wordCount, gridRow + 1, gridColumn, currentWordIndex);
	}

	// Go left
	if (gridColumn > 0 && (strcmp(words[currentWordIndex], grid[gridRow][gridColumn - 1]) == 0))
	{
		readCount += countReadsRecoursive(grid, gridRows, gridColumns, words, wordCount, gridRow, gridColumn - 1, currentWordIndex);
	}

	return readCount;
}

int countReads(char grid[30][30][101], int gridRows, int gridColumns, char sentence[90901])
{
	char words[909][101] = {};
	int wordCount = 1;
	getSentenceWords(sentence, words, wordCount);

	int totalReads = 0;
	for (int i = 0; i < gridRows; i++)
	{
		for (int j = 0; j < gridColumns; j++)
		{
			if (strcmp(grid[i][j], words[0]) == 0)
			{
				totalReads += countReadsRecoursive(grid, gridRows, gridColumns, words, wordCount, i, j);
			}
		}
	}

	return totalReads;
}

int main()
{
	char grid[30][30][101] = {
		{"cat", "dog"},
		{"tiger", "cat"}};
	char sentence[101] = "cat dog";

	char grid1[30][30][101] = {
		{"one", "two", "three"},
		{"four", "five", "six"}};
	char sentence1[101] = "one two three two five";

	char grid2[30][30][101] = {
		{"cat"}};
	char sentence2[101] = "cat";

	std::cout << countReads(grid, 2, 2, sentence) << '\n';
	std::cout << countReads(grid1, 2, 3, sentence1) << '\n';
	std::cout << countReads(grid2, 1, 1, sentence2) << '\n';
	return 0;
}