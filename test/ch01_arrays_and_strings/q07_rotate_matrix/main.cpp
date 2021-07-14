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

#include "ctcilib/assorted_methods.cpp"

#include <iostream>

void Rotate(std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t layer = 0; layer < n/2; layer++) {
        size_t last{n-layer-1};
        for (size_t i = layer; i < last; i++) {
            // we don't want to subtract the layer value from last when subtracting i
            size_t offset{i-layer};
            std::swap(matrix[layer][i], matrix[i][last]);
            std::swap(matrix[last-offset][layer], matrix[layer][i]);
            std::swap(matrix[last][last-offset], matrix[last-offset][layer]);
        }
    }
}

/*
void Rotate(std::vector<std::vector<int>>& matrix) {
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
}
*/

int main() {
    std::vector< std::vector<int> > matrix = ctcilib::random_matrix(3, 3, 0, 9);
    ctcilib::print_matrix(matrix);
    Rotate(matrix);
    std::cout << std::endl;
    ctcilib::print_matrix(matrix);
	return 0;
}