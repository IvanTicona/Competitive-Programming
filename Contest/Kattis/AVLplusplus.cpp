#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_m = 105;
const int MAX_h = 1010;
long long dp[MAX_m][MAX_h];

void calculateDP() {

    for (int m = 0; m <= MAX_m; ++m) {
        for (int h = 0; h <= MAX_h; ++h) {
            long long count = 0;

            // Probar todas las combinaciones de alturas de subárboles izquierdo y derecho
            for (int left = 0; left < h; ++left) {
                for (int right = 0; right < h; ++right) {
                    if (abs(left - right) <= m) {
                        count += dp[m][left] * dp[m][right];
                    }
                }
            }

            dp[m][h] = count;
        }
    }
}

int main() {

    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);

    int m, h;
    // cout << "Ingrese el valor de m: ";
    cin >> m;
    // cout << "Ingrese la altura h: ";
    cin >> h;

    // Calcular el DP
    calculateDP();

    // Mostrar el resultado para AVL-m con altura h
    cout << "Número de formas de árboles AVL-" << m << " con altura " << h << ": " << dp[m][h] << endl;

    return 0;
}
