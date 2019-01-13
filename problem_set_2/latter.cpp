#include <iostream>

using namespace std;

int ladderSum(int matrix[100][100], unsigned int rows, unsigned int columns, unsigned int startRow, unsigned int startColumn)
{
	int sum = 0;
	int row = startRow;
	int col = startColumn;
	bool shouldTurnRight = true;
	while (row < rows && col < columns)
	{
		sum += matrix[row][col];
		if (shouldTurnRight)
		{
			col++;
		}
		else
		{
			row++;
		}
		shouldTurnRight = !shouldTurnRight;
	}
	return sum;
}

int main()
{
	int matrix1[100][100] = {
		{1}
	};
	int matrix2[100][100] = {
		{1, 2, 3},
		{4, 5, 6}};
	std::cout << ladderSum(matrix1, 1, 1, 0, 0) << '\n';
	std::cout << ladderSum(matrix2, 2, 3, 0, 1) << '\n';
	return 0;
}