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
	int matrix3[100][100] = {
        {25}
    };
	int matrix4[100][100] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
	int matrix5[100][100] = {
        {1,2,3,4},
        {4,5,6,5}
    }; 
	int matrix6[100][100] = {
        {9,8,5,7,8,8,9,8},
        {6,9,8,4,9,3,2,1},
        {1,5,3,9,2,8,2,8},
        {6,3,5,2,1,4,3,4},
        {5,9,8,5,3,4,7,7},
        {6,9,8,9,6,8,7,7},
        {2,4,9,6,4,1,2,1},
        {4,2,5,3,7,7,8,5},
        {5,2,1,9,2,4,0,0},
        {5,3,3,4,3,1,1,1}
    };
 
	std::cout << ladderSum(matrix1, 1, 1, 0, 0) << '\n';
	std::cout << ladderSum(matrix2, 2, 3, 0, 1) << '\n';
	std::cout << ladderSum(matrix3, 1, 1, 0, 0) << '\n';
	std::cout << '\n';
	
	std::cout << ladderSum(matrix4, 3, 3, 0, 0) << '\n';
    std::cout << ladderSum(matrix4, 3, 3, 0, 1) << '\n';
    std::cout << ladderSum(matrix4, 3, 3, 1, 1) << '\n';
    std::cout << ladderSum(matrix4, 3, 3, 0, 2) << '\n';
	std::cout << '\n';

	std::cout << ladderSum(matrix5, 2, 4, 0, 0) << '\n';
    std::cout << ladderSum(matrix5, 2, 4, 0, 1) << '\n';
    std::cout << ladderSum(matrix5, 2, 4, 1, 3) << '\n';
    std::cout << ladderSum(matrix5, 2, 4, 1, 0) << '\n';
	std::cout << '\n';

    std::cout << ladderSum(matrix6, 10, 8, 0, 0) << '\n';
    std::cout << ladderSum(matrix6, 10, 8, 1, 1) << '\n';
    std::cout << ladderSum(matrix6, 10, 8, 7, 4) << '\n';
    std::cout << ladderSum(matrix6, 10, 8, 3, 1) << '\n';
    std::cout << ladderSum(matrix6, 10, 8, 6, 5) << '\n';

	return 0;
}