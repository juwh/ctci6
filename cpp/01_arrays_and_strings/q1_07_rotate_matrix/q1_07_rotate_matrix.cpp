//
// Created by William Ju on 10/7/17.
//

#include <iostream>
#include "../../ctcilib/ctcilib/assorted_methods.cpp"

bool rotate(std::vector< std::vector<int> >& matrix) {
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
    std::vector< std::vector<int> > matrix = randomMatrix(3, 3, 0, 9);
    printMatrix(matrix);
    rotate(matrix);
    std::cout << std::endl;
    printMatrix(matrix);
}