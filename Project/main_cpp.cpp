#include <vector>

std::vector<std::vector<int>> rotateLeft(std::vector<std::vector<int>> matrix)
{
	const int size = matrix.size();
	if (matrix[0].size() != size) return matrix; // should be nxn matrix
	for (auto row = 0; row < size / 2; ++row)
	{
		for (auto col = row; col < size - row - 1; ++col)
		{
			auto tmp = matrix[row][col];
			matrix[row][col] = matrix[col][size - row - 1]; // right -> left
			matrix[col][size - row - 1] = matrix[size - row - 1][size - col - 1]; // bottom -> top
			matrix[size - row - 1][size - col - 1] = matrix[size - col - 1][row]; // left -> right
			matrix[size - col - 1][row] = tmp; // top -> bottom
		}
	}
	return matrix;
}

std::vector<std::vector<int>> rotateRight(std::vector<std::vector<int>> matrix)
{
	const int size = matrix.size();
	if (matrix[0].size() != size) return matrix; // should be nxn matrix
	for (auto row = 0; row < size / 2; ++row)
	{
		for (auto col = row; col < size - row - 1; ++col)
		{
			auto tmp = matrix[row][col];
			matrix[row][col] = matrix[size - col - 1][row]; // bottom -> top	
			matrix[size - col - 1][row] = matrix[size - row - 1][size - col - 1]; // left -> right
			matrix[size - row - 1][size - col - 1] = matrix[col][size - row - 1]; // top -> bottom
			matrix[col][size - row - 1] = tmp; // right -> left
		}
	}
	return matrix;
}
