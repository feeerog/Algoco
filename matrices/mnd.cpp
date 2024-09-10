#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() para inicializar el generador de números aleatorios

using namespace std;

// Función para generar una matriz aleatoria de tamaño n x m
void generarMatrizAleatoria(vector<vector<int>>& matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100;  // Valores aleatorios entre 0 y 99
        }
    }
}

// Multiplicación de matrices A(n x m) y B(m x p), resultado en C(n x p)
void multiplicacionMatriz(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n, int m, int p) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    srand(time(0));  // Inicializar el generador de números aleatorios

    // Definir diferentes tamaños de matrices
    vector<pair<int, int>> tamanios_matriz_A = {{2, 3},{22, 32},{50, 64},{30, 80},{100, 200},{230, 335}, {500, 400},{400, 700}, {600, 800},{1000, 500}};
    vector<pair<int, int>> tamanios_matriz_B = {{3, 4},{32, 43},{64, 70},{80, 54},{200, 150},{335, 200}, {400, 600}, {700, 300},{800, 700},{500, 1000}};


    for (size_t i = 0; i < tamanios_matriz_A.size(); ++i) {
        int n = tamanios_matriz_A[i].first;  // Filas de A
        int m = tamanios_matriz_A[i].second; // Columnas de A (y filas de B)
        int p = tamanios_matriz_B[i].second; // Columnas de B

        cout << "Prueba para matrices A: " << n << "x" << m << " y B: " << m << "x" << p << endl;

        // Crear matrices A (n x m), B (m x p) y C (n x p)
        vector<vector<int>> A(n, vector<int>(m));
        vector<vector<int>> B(m, vector<int>(p));
        vector<vector<int>> C(n, vector<int>(p, 0));

        // Generar matrices aleatorias
        generarMatrizAleatoria(A, n, m);
        generarMatrizAleatoria(B, m, p);

        // Medir el tiempo para la multiplicación de matrices
        auto inicio = chrono::high_resolution_clock::now();
        multiplicacionMatriz(A, B, C, n, m, p);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;

        cout << "Tiempo para la multiplicacion de matrices A y B: " << duracion.count() << " segundos" << endl;
    }

    return 0;
}
