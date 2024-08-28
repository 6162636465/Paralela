#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiply_matrices_block(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int blockSize) {
    int N = A.size();
    
    // Asumimos que las matrices son cuadradas y de tamaño N x N
    for (int i = 0; i < N; i += blockSize) {
        for (int j = 0; j < N; j += blockSize) {
            for (int k = 0; k < N; k += blockSize) {
                // Multiplicación de bloques
                for (int ii = i; ii < min(i + blockSize, N); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, N); ++jj) {
                        int sum = 0;
                        for (int kk = k; kk < min(k + blockSize, N); ++kk) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    const int N = 1500; // Tamaño de la matriz
    const int blockSize = 30; // Tamaño del bloque

    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));

    auto start = high_resolution_clock::now();

    multiply_matrices_block(A, B, C, blockSize);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Tiempo de ejecución: " << duration.count() << " milisegundos" << endl;
    cout << "Tam de la matriz: " << N << " numero de Bloques"<<blockSize << endl;
    return 0;
}
