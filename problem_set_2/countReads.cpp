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

	char grid3[30][30][101] = {
        {"is", "the", "question"},
        {"that", "be", "or"},
        {"be", "to", "not"},
        {"or", "not", "to"}
    };
    char sentence3[101] = "to be or not to be that is the question";
 
    std::cout << (countReads(grid3, 4, 3, sentence3) == 4);

	char grid4[30][30][101] = {
        {"fence", "cow", "fence"},
        {"chicken", "pig", "cow"},
        {"fence", "chicken", "fence"}
    };
    char sentence4[101] = "chicken pig cow";
 
    std::cout << (countReads(grid4, 3, 3, sentence4) == 4);

	char grid5[30][30][101] = {
        {"the", "quick", "brown"},
        {"lazy", "dog", "fox"},
        {"the", "over", "jumped"}
    };
    char sentence51[101] = "the quick brown fox jumped over the lazy dog";
    char sentence52[101] = "dog lazy the over jumped fox brown quick the";
 
    std::cout << (countReads(grid5, 3, 3, sentence51) == 1);
    std::cout << (countReads(grid5, 3, 3, sentence51) == 1);

	char grid6[30][30][101] = {
        {"is", "it", "crazy", "how"},
        {"creates", "backwards", "sentences", "saying"},
        {"backwards", "sentences", "saying", "how"},
        {"ignore", "is", "it", "crazy"}
    };
    char sentence6[101] = "is it crazy how saying sentences backwards creates backwards sentences saying how crazy it is";
 
    std::cout << (countReads(grid6, 4, 4, sentence6) == 25);

	char grid7[30][30][101] = {
        {"cow", "cow"},
        {"cow", "cow"}
    };
    char sentence7[101] = "cow cow";
 
    std::cout << (countReads(grid7, 2, 2, sentence7) == 8);

	return 0;
}