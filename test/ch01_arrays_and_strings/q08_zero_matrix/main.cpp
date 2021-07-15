#pragma region Interview Question
/*
1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its
entire row and column are set to 0.
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#17. If you just cleared the rows and columns as you found 0s, you'd likely wind up
clearing the whole matrix. Try finding the cells with zeros first before making any
changes to the matrix.

#74. Can you use O(N) additional space instead of O(N^2)? What information do you really
need from the list of cells that are zero?

#102. You probably need some data storage to maintain a list of the rows and columns that 
need to be zeroed. Can you reduce the additional space usage to O(1) by using the matrix
itself for data storage?
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>

#include <iostream>
#include <vector>

void ZeroRow(std::vector<std::vector<int>> &matrix, size_t row) {
	for (size_t col = 0; col < matrix[row].size(); col++) {
		matrix[row][col] = 0;
	}
}

void ZeroCol(std::vector<std::vector<int>> &matrix, size_t col) {
	for (size_t row = 0; row < matrix.size(); row++) {
		matrix[row][col] = 0;
	}
}

void SetZeros(std::vector<std::vector<int>> &matrix) {
	std::vector<bool> zero_row(matrix.size());
	std::vector<bool> zero_col(matrix[0].size());

	// Store the row and column index with value 0
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < matrix[0].size(); j++) {
			if (!matrix[i][j]) {
				zero_row[i] = true;
				zero_col[j] = true;
			}
		}
	}

	// Nullify rows
	for (size_t i = 1; i < zero_row.size(); i++) {
		if (zero_row[i]) {
			ZeroRow(matrix, i);
		}
	}

	// Nullify columns
	for (size_t j = 1; j < zero_col.size(); j++) {
		if (zero_col[j]) {
			ZeroCol(matrix, j);
		}
	}
}

void SetZerosInPlace(std::vector<std::vector<int>> &matrix) {
	bool zero_row{false};
	bool zero_col{false};

	// Check if first row has a zero
	for (size_t j = 0; j < matrix[0].size() && !zero_row; j++) {
		if (!matrix[0][j]) {
			zero_row = true;
		}
	}

	// Check if first column has a zero
	for (size_t i = 0; i < matrix.size() && !zero_col; i++) {
		if (!matrix[i][0]) {
			zero_col = true;
		}
	}

	// Check for zeros in the rest of the array
	for (size_t i = 1; i < matrix.size(); i++) {
		for (size_t j = 1; j < matrix[0].size(); j++) {
			if (!matrix[i][j]) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	// Nullify rows based on values in first column
	for (size_t i = 1; i < matrix.size(); i++) {
		if (!matrix[i][0]) {
			ZeroRow(matrix, i);
		}
	}

	// Nullify columns based on values in first row
	for (size_t j = 1; j < matrix[0].size(); j++) {
		if (!matrix[0][j]) {
			ZeroCol(matrix, j);
		}
	}

	// Nullify first row
	if (zero_row) {
		ZeroRow(matrix, 0);
	}

	// Nullify first column
	if (zero_col) {
		ZeroCol(matrix, 0);
	}
}

bool MatricesAreEqual(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2) {
	if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) {
		return false;
	}
	
	for (size_t k = 0; k < m1.size(); k++) {
		for (size_t j = 0; j < m1[0].size(); j++) {
			if (m1[k][j] != m2[k][j]) {
				return false;
			}
		}
	}	
	return true;
}

std::vector<std::vector<int>> CloneMatrix(std::vector<std::vector<int>> matrix) {
	std::vector<std::vector<int>> c(matrix.size(), std::vector<int>(matrix[0].size(), 0));
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < matrix[0].size(); j++) {
			c[i][j] = matrix[i][j];
		}
	}
	return c;
}

int main() {
	size_t nrows{10};
	size_t ncols{15};
	std::vector<std::vector<int>> matrix1 = ctcilib::random_matrix(nrows, ncols, -10, 10);
	std::vector<std::vector<int>> matrix2 = CloneMatrix(matrix1);

	ctcilib::print_matrix(matrix1);
	
	SetZeros(matrix1);
	SetZerosInPlace(matrix2);
	
	std::cout << std::endl;
	
	ctcilib::print_matrix(matrix1);
	std::cout << std::endl;
	ctcilib::print_matrix(matrix2);
	
	if (MatricesAreEqual(matrix1, matrix2)) {
		std::cout << "Equal" << std::endl;
	} else {
		std::cout << "Not Equal" << std::endl;
	}
}