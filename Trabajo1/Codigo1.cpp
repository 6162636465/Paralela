#include <iostream>
#include <chrono>

const int MAX = 90000; // Puedes ajustar el valor de MAX según tus necesidades
double A[MAX][MAX], x[MAX], y[MAX];

int main() {
    // Inicializar A y x, y asignar y = 0
    for (int i = 0; i < MAX; ++i) {
        x[i] = 1.0; // Puedes ajustar los valores según sea necesario
        y[i] = 0.0;
        for (int j = 0; j < MAX; ++j) {
            A[i][j] = 1.0; // Puedes ajustar los valores según sea necesario
        }
    }

    // Medir el tiempo de la primera pareja de bucles
    auto start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    std::cout << "Tiempo de ejecución del primer par de bucles: " << elapsed1.count() << " segundos\n";

    // Asignar y = 0
    for (int i = 0; i < MAX; ++i) {
        y[i] = 0.0;
    }

    // Medir el tiempo de la segunda pareja de bucles
    auto start2 = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    std::cout << "Tiempo de ejecución del segundo par de bucles: " << elapsed2.count() << " segundos\n";
    std::cout << "Con esta cantidad de datos " << MAX<< "\n";
    return 0;
}
