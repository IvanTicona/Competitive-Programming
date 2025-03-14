#include <bits/stdc++.h>
using namespace std;

struct User {
    int index;
    long long left, right;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<User> users(n);
        for (int i = 0; i < n; i++) {
            users[i].index = i;
            cin >> users[i].left >> users[i].right;
        }

        // Ordenar usuarios por `left` ascendente y `right` descendente
        sort(users.begin(), users.end(), [](const User& a, const User& b) {
            return a.left < b.left || (a.left == b.left && a.right > b.right);
        });

        vector<long long> answers(n, 0);
        long long L_pred = 1, R_pred = 1e9; // Inicializamos el rango predicho
        set<pair<long long, long long>> active; // Activo: (right, left)

        for (const auto& user : users) {
            // Verificar predictores que cubren completamente el rango del usuario actual
            bool has_predictor = false;
            L_pred = 1, R_pred = 1e9;

            for (const auto& predictor : active) {
                if (predictor.second <= user.left && predictor.first >= user.right) {
                    has_predictor = true;
                    L_pred = max(L_pred, predictor.second);
                    R_pred = min(R_pred, predictor.first);
                }
            }

            // Calcular strongly recommended tracks
            if (has_predictor) {
                long long left_gap = max(0LL, user.left - L_pred);
                long long right_gap = max(0LL, R_pred - user.right);
                answers[user.index] = left_gap + right_gap;
            } else {
                answers[user.index] = 0;
            }

            // Agregar el rango actual al conjunto de predictores activos
            active.insert({user.right, user.left});
        }

        for (int i = 0; i < n; i++) {
            cout << answers[i] << "\n";
        }
    }
    return 0;
}
