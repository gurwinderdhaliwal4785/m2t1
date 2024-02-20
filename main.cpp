#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

int main() {
    // Initialize matrices with random values
    int n = 10; // Size of the matrices
    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<vector<int>> B(n, vector<int>(n, 0));
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }

    // Perform matrix multiplication
    auto start = chrono::steady_clock::now();
    vector<vector<int>> C = matrixMultiply(A, B);
    auto end = chrono::steady_clock::now();
    
    // Write output to a file
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                outputFile << C[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
    }

    // Calculate execution time
    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
