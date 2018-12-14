#include <iostream>

using namespace std;

const int MAX = 100;

template <typename T>
void cross_merge(T a[MAX][MAX], T b[MAX][MAX], int size, T buffer[MAX][MAX])
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0, h = 0; j < 2 * size; j++)
		{
			if (k++ % 2 == 0)
			{
				buffer[i][j] = a[i][h];
			}
			else
			{
				buffer[i][j] = b[i][h++];
			}
		}

		k++;
	}
}

template <typename T>
void print_array(T arr[MAX][MAX], int w, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

template <typename T>
void transpose(T arr[MAX][MAX], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int s = 3;
	int a[MAX][MAX] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};
	int b[MAX][MAX] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1}};
	int merged[MAX][MAX] = {};

	cross_merge(a, b, s, merged);
	print_array(merged, 2 * s, s);

	
	return 0;
}