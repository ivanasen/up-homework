#include <iostream>
#include <cstring>

using namespace std;

const int N = 5;
const int WORD = 9;

bool is_palindrome(char *word)
{
	int len = strlen(word);
	for (int i = 0; i <= len / 2; i++)
	{
		if (word[i] != word[len - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int get_palindromes_over_diagonal(char words[N][N][WORD])
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (is_palindrome(words[i][j]))
			{
				count++;
			}
		}
	}
	return count;
}

int get_string_count_under_secondary_diagonal(char words[N][N][WORD], char *word)
{
	int count = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = N - i; j < N; j++)
		{
			if (strcmp(words[i][j], word) == 0)
			{
				count++;
			}
		}
	}
	return count;
}

bool do_diagonals_match(char words[N][N][WORD])
{
	for (int i = 0; i < N; i++)
	{
		if (strcmp(words[i][i], words[N - i - 1][N - i - 1]) != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char words[N][N][WORD] = {
		{"Pesho", "AbbA", "ababa", "Kiro", "kuchhcuk"},
		{"Pesho", "AbbA", "ababa", "Kiro", "kuchhcuk"},
		{"Pesho", "AbbA", "ababa", "Kiro", "kuchhcuk"},
		{"Pesho", "AbbA", "ababa", "Kiro", "kuchhcuk"},
		{"Pesho", "AbbA", "ababa", "Kiro", "kuchhcuk"}};

	int palindromes = get_palindromes_over_diagonal(words);
	cout << "Palindromes over diagonal: " << palindromes << '\n';

	char word[WORD] = "Kiro";
	int count = get_string_count_under_secondary_diagonal(words, word);
	cout << "String count under diagonal: " << count << '\n';

	cout << "The Diagonals do";
	if (!do_diagonals_match(words))
	{
		cout << "n\'t ";
	}
	cout << "match" << '\n';

	return 0;
}