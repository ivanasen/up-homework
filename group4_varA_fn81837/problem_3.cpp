#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20;
const int WORD_MAX = 50;

bool is_lower_case(char *word)
{
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if (word[i] < 'a' || word[i] > 'z')
		{
			return false;
		}
	}
	return true;
}

void lowercase_reversed(char words[MAX][WORD_MAX], int n, char result[MAX * WORD_MAX])
{
	int result_length = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (is_lower_case(words[i]))
		{
			result_length += strlen(words[i]);
			strcat(result, words[i]);
		}
	}
	result[result_length] = '\0';
}

void read_input(char words[MAX][WORD_MAX], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
}

void solve()
{
	char words[MAX][WORD_MAX] = {};
	int n;
	read_input(words, n);
	char result[MAX * WORD_MAX] = "";
	lowercase_reversed(words, n, result);
	cout << result << '\n';
}

int main()
{
	solve();
	return 0;
}