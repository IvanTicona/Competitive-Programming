#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Función para calcular el puntaje de Bob y Alice dado un número de grupos
bool canDivide(const string &s, int n, int m, long long k) {
    int groupSize = n / m;  // Tamaño base de cada grupo
    int extraGroups = n % m; // Grupos con un elemento extra

    long long bobScore = 0, aliceScore = 0;
    int currentGroup = 0;

    // Inicializamos el índice de grupo
    for (int i = 0; i < n; i++) {
        if (i == currentGroup * groupSize + min(currentGroup, extraGroups)) {
            currentGroup++; // Pasamos al siguiente grupo
        }
        if (s[i] == '1') {
            bobScore += currentGroup;
        } else {
            aliceScore += currentGroup;
        }
    }

    return bobScore - aliceScore >= k;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        string s;
        cin >> s;

        // Búsqueda binaria para minimizar m
        int left = 1, right = n, result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canDivide(s, n, mid, k)) {
                result = mid; // Guardamos el resultado
                right = mid - 1; // Intentamos con menos grupos
            } else {
                left = mid + 1; // Necesitamos más grupos
            }
        }

        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
