#include <iostream>
#include <cstring>

using namespace std;

const int N = 20;

int get_word_count_in_array(char arr[N][N], int n, char *word)
{
	int count = 0;
	int word_length = strlen(word);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n - word_length; j++)
		{
			for (int k = j; k < j + word_length; k++)
			{
				if (arr[i][k] != word[k - j])
				{
					break;
				}
				if (k == j + word_length - 1)
				{
					count++;
				}
			}
		}
	}
	return count;
}

void read_input(char arr[N][N], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solve()
{
	char word[] = "dog";
	char arr[N][N] = {};
	int n;

	read_input(arr, n);
	int word_count = get_word_count_in_array(arr, n, word);
	cout << word_count << '\n';
}

int main()
{
	solve();
	return 0;
}