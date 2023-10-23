#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // For formatting output

int main() {
    // Open the file for reading
    std::ifstream file("matrix.txt");

    if (!file.is_open()) {
        std::cerr << "File not found or unable to open." << std::endl;
        return 1;
    }

    int rows, cols;
    file >> rows >> cols;

    // Create a vector to store the matrix
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    // Read the matrix elements from the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }

    // Close the file
    file.close();

    // Print the matrix neatly
    std::cout << "Matrix " << rows << " x " << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Adjust the width as needed for formatting
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
