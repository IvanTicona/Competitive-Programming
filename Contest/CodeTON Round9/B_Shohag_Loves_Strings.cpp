#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

// Función que calcula el hash de un substring usando rolling hash
long long getHash(const string &s, int start, int length, const vector<long long> &powBase) {
    long long hash = 0;
    for (int i = start; i < start + length; ++i) {
        hash = (hash * BASE + (s[i] - 'a' + 1)) % MOD;
    }
    return hash;
}

// Función principal para resolver el problema
void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        // Preparar potencias de BASE para hashing rolling
        vector<long long> powBase(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            powBase[i] = (powBase[i - 1] * BASE) % MOD;
        }

        // Intentamos encontrar un substring cuya cantidad de substrings distintos sea par
        bool found = false;

        // Proceso para encontrar un substring con f(p) par
        for (int start = 0; start < n; ++start) {
            unordered_set<long long> seenHashes; // Para almacenar los hashes únicos de los substrings
            long long currentHash = 0;

            // Generamos substrings empezando desde la posición 'start'
            for (int end = start; end < n; ++end) {
                currentHash = (currentHash * BASE + (s[end] - 'a' + 1)) % MOD;

                seenHashes.insert(currentHash);
                
                // Si encontramos un número par de substrings distintos
                if (seenHashes.size() % 2 == 0) {
                    cout << s.substr(start, end - start + 1) << '\n';
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
