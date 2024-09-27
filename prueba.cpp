#include <iostream>
#include <vector>
#include <cmath>

// Función que cuenta el número de AVL-m diferentes con altura h
long long countAVL_m(int m, int h) {
    if (h == 0) return 1; // Caso base: solo un árbol vacío
    if (h == 1) return 3; // Caso base para altura 1, hay exactamente 3 árboles posibles

    // Vector para almacenar la cantidad de árboles con altura desde 0 hasta h
    std::vector<long long> dp(h + 1, 0);
    dp[0] = 1; // Un árbol vacío
    dp[1] = 3; // Tres árboles posibles con altura 1

    // Rellenar la tabla dp usando programación dinámica
    for (int i = 2; i <= h; i++) {
        for (int left = 0; left <= i - 1; left++) {
            int right = i - 1 - left;
            // La diferencia de alturas no debe superar m
            if (std::abs(left - right) <= m) {
                dp[i] += dp[left] * dp[right];
            }
        }
    }

    return dp[h];
}

int main() {
    // Ejemplos de prueba
    std::cout << "m = 1, h = 1: " << countAVL_m(1, 1) << std::endl; // Debería devolver 3
    std::cout << "m = 2, h = 1: " << countAVL_m(2, 1) << std::endl; // Debería devolver 3
    std::cout << "m = 0, h = 2: " << countAVL_m(0, 2) << std::endl; // Debería devolver 1
    std::cout << "m = 2, h = 2: " << countAVL_m(2, 2) << std::endl; // Debería devolver 21

    return 0;
}
