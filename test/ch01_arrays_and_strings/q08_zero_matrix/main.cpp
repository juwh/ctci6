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

#include "ctcilib/assorted_methods.cpp"

#include <iostream>
#include <vector>

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
	
	//QuestionA.setZeros(matrix1);
	//QuestionB.setZeros(matrix2);
	
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