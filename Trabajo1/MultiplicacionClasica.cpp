#include <iostream>
#include <chrono>
#include <vector>

const int SIZE = 1500; // Tamaño de la matriz (puedes ajustar según tus necesidades)

// Función para multiplicar matrices A y B, y almacenar el resultado en C
void multiplyMatrices(const std::vector<std::vector<double>>& A, 
                      const std::vector<std::vector<double>>& B, 
                      std::vector<std::vector<double>>& C) {
    // Inicializar la matriz C con ceros
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            C[i][j] = 0.0;
        }
    }

    // Medir el tiempo de ejecución
    auto start = std::chrono::high_resolution_clock::now();

    // Multiplicación de matrices usando tres bucles anidados
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "Tiempo de ejecución de la multiplicación de matrices: " << elapsed.count() << " milisegundos\n";
    std::cout << "Tam de la matriz: " << SIZE<< " \n";

}

int main() {
    // Inicializar las matrices A, B y C
    std::vector<std::vector<double>> A(SIZE, std::vector<double>(SIZE));
    std::vector<std::vector<double>> B(SIZE, std::vector<double>(SIZE));
    std::vector<std::vector<double>> C(SIZE, std::vector<double>(SIZE));

    // Inicializar las matrices A y B con algunos valores (por ejemplo, 1.0)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    // Llamar a la función de multiplicación de matrices
    multiplyMatrices(A, B, C);

    return 0;
}
