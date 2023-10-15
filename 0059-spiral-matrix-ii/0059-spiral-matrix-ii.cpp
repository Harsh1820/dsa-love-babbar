class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create an empty matrix of size n x n
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        // If n is 1, set the only element and return
        if (n == 1) {
            matrix[0][0] = 1;
            return matrix;
        }

        int row = 0;
        int col = 0;
        int count = 1;

        while (n > 0) {
            if (n == 1) {
                matrix[row][col] = count;
                break;
            }

            // Move right and fill values
            for (int k = 0; k < n - 1; k++) {
                matrix[row][col] = count;
                col++;
                count++;
            }

            // Move down and fill values
            for (int k = 0; k < n - 1; k++) {
                matrix[row][col] = count;
                row++;
                count++;
            }

            // Move left and fill values
            for (int k = 0; k < n - 1; k++) {
                matrix[row][col] = count;
                col--;
                count++;
            }

            // Move up and fill values
            for (int k = 0; k < n - 1; k++) {
                matrix[row][col] = count;
                row--;
                count++;
            }

            // Adjust pointers and decrement size for the next layer
            row += 1;
            col += 1;
            n -= 2;
        }

        return matrix;
    }
};