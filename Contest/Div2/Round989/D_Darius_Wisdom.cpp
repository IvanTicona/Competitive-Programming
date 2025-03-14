#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> pos_0, pos_1, pos_2;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) pos_0.push_back(i);
            else if (a[i] == 1) pos_1.push_back(i);
            else pos_2.push_back(i);
        }

        vector<pair<int, int>> moves;

        // Movimientos de 2 -> 1
        while (!pos_2.empty() && pos_1.size() < n - pos_0.size()) {
            int u = pos_2.back(); pos_2.pop_back();
            int v = pos_1.back(); pos_1.pop_back();
            moves.push_back({u + 1, v + 1});
            pos_1.push_back(v);
        }

        // Movimientos de 1 -> 0
        while (!pos_1.empty() && pos_0.size() < count(a.begin(), a.end(), 0)) {
            int u = pos_1.back(); pos_1.pop_back();
            int v = pos_0.back(); pos_0.pop_back();
            moves.push_back({u + 1, v + 1});
            pos_0.push_back(v);
        }

        // Imprimir los resultados
        cout << moves.size() << "\n";
        for (auto &[u, v] : moves) {
            cout << u << " " << v << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
