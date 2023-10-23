// EECS 348 Lab 6
// Name: Ella Nguyen
// ID: 3098942
// Goal: A program that performs various operations on square matrices using functions and arrays
// Functions: Read matrix data from a file, perform matrix operations, output results

#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& N, std::ifstream& inputFile);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N);
void subtractMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N);

int main() {
    int N;
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int sum[MAX_SIZE][MAX_SIZE];
    int product[MAX_SIZE][MAX_SIZE];
    int difference[MAX_SIZE][MAX_SIZE];

    std::ifstream inputFile("matrix_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file." << std::endl;
        return 1;
    }

    inputFile >> N;

    std::cout << "Ella Nguyen" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    readMatrix(A, N, inputFile);
    printMatrix(A, N);

    std::cout << "\nMatrix B:" << std::endl;
    readMatrix(B, N, inputFile);
    printMatrix(B, N);

    // Add matrices A and B
    addMatrices(A, B, sum, N);
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    printMatrix(sum, N);

    // Multiply matrices A and B
    multiplyMatrices(A, B, product, N);
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    printMatrix(product, N);

    // Subtract matrix B from A
    subtractMatrices(A, B, difference, N);
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    printMatrix(difference, N);

    inputFile.close();

    return 0;
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& N, std::ifstream& inputFile) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void subtractMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}