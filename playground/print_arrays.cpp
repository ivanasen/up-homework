#include <iostream>
#include <vector>

using namespace std;

void log(int e)
{
	cout << e << ' ';
}

void print_spiral_array(vector<vector<int>> arr)
{
	int size = arr.size();

	int padding = size / 2 - (size % 2 == 0 ? 1 : 0);
	while (padding >= 0)
	{
		int i = padding;
		int j = padding + 1;
		for (; j < size - padding; j++)
		{
			log(arr[i][j]);
		}
		j--;
		i++;

		for (; i < size - padding; i++)
		{
			log(arr[i][j]);
		}
		i--;
		j--;

		for (; j >= padding; j--)
		{
			log(arr[i][j]);
		}
		j++;
		i--;

		if (i < padding)
		{
			log(arr[j][j]);
		}

		for (; i >= padding; i--)
		{
			log(arr[i][j]);
		}

		padding--;
	}
}

void print_frame_array(vector<vector<int>> arr)
{
	int frame = 1;
	int i = 0;
	int j = 0;
	while (frame <= arr.size())
	{
		for (; j < frame; j++)
		{
			log(arr[i][j]);
		}
		j--;
		for (--i; i >= 0; i--)
		{
			log(arr[i][j]);
		}
		frame++;
		j = 0;
		i = frame - 1;
	}
}

void print_halfway_diagonal_array(vector<vector<int>> arr)
{
	int i = 0;
	while (i < arr.size())
	{
		int row = i;
		int col = 0;

		while (row >= col)
		{
			log(arr[row][col]);
			row--;
			col++;
		}

		i++;
	}
	i = 1;
	while (i < arr.size())
	{
		int row = arr.size() - 1;
		int col = i;

		while (row >= col)
		{
			log(arr[row][col]);
			row--;
			col++;
		}

		i++;
	}
}

void print_diagonal_array(vector<vector<int>> arr)
{
	int i = 0;
	while (i < arr.size())
	{
		int row = i;
		int col = 0;

		while (row >= 0)
		{
			log(arr[row][col]);
			row--;
			col++;
		}

		i++;
	}
	i = 1;
	while (i < arr.size())
	{
		int row = arr.size() - 1;
		int col = i;

		while (col < arr.size())
		{
			log(arr[row][col]);
			row--;
			col++;
		}

		i++;
	}
}

void print_half_diagonal_array(vector<vector<int>> arr)
{
	int i = 0;
	while (i < arr.size())
	{
		int row = i;
		int col = 0;

		while (row >= 0)
		{
			log(arr[row][col]);
			row--;
			col++;
		}

		i++;
	}
}

void print_top_down_diagonal_array(vector<vector<int>> arr)
{
	int size = arr.size();
	int i = 0;
	while (i < size)
	{
		int row = size - i - 1;
		while (row < arr.size())
		{
			log(arr[row][i]);
			row++;
		}
		i++;
	}
}

int main()
{
	vector<vector<int>> arr{
		{1, 2, 3, 4},
		{6, 7, 8, 9},
		{11, 12, 13, 14},
		{16, 17, 18, 19}};

	cout << "Spiral: ";
	print_spiral_array(arr);
	cout << '\n';

	cout << "Framed: ";
	print_frame_array(arr);
	cout << '\n';

	cout << "Halfway-Diagonal: ";
	print_halfway_diagonal_array(arr);
	cout << '\n';

	cout << "Diagonal: ";
	print_diagonal_array(arr);
	cout << '\n';

	cout << "Half-Diagonal: ";
	print_half_diagonal_array(arr);
	cout << '\n';

	cout << "Top-Down-Diagonal: ";
	print_top_down_diagonal_array(arr);
	cout << '\n';

	return 0;
}