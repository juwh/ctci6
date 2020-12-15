#pragma region Interview Question
/*
1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the
image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#51 Try thinking about it layer by layer. Can you rotate a specific layer?

#100. Rotating a specific layer would just mean swapping the values in four arrays. If
you were asked to swap the values in two arrays, could you do this? Can you then extend
it to four arrays?
*/
#pragma endregion

#include <iostream>

#include "../../ctcilib/ctcilib/assorted_methods.cpp"

bool Rotate(std::vector< std::vector<int> >& matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];

            // left -> top
            matrix[first][i] = matrix[last-offset][first];

            // bottom -> left
            matrix[last-offset][first] =
                    matrix[last][last-offset];

            // right -> bottom
            matrix[last][last-offset] =
                    matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }
    return true;
}

int main() {
    std::vector< std::vector<int> > matrix = RandomMatrix(3, 3, 0, 9);
    PrintMatrix(matrix);
    Rotate(matrix);
    std::cout << std::endl;
    PrintMatrix(matrix);
	return 0;
}