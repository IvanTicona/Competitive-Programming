#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Leer n y q
    ll n, q;
    cin >> n >> q;
    
    // Leer q operaciones
    // Cada operación es "si +" o "si -"
    vector<pair<ll, char>> operations(q);
    for(int i=0; i<q; ++i){
        ll si;
        char op;
        cin >> si >> op;
        operations[i] = {si, op};
    }
    
    // Contar el número de operaciones de expansión para cada serpiente
    vector<int> e(n+1, 0); // e[i] = número de '+'
    vector<int> s(n+1, 0); // s[i] = número de '-'
    for(int i=0; i<q; ++i){
        ll si = operations[i].first;
        char op = operations[i].second;
        if(op == '+') e[si]++;
        else s[si]++;
    }
    
    // Crear una lista de serpientes con su índice y e_i
    vector<pair<int, int>> snakes; // {e_i, s_i}
    for(int i=1; i<=n; ++i){
        snakes.emplace_back(e[i], s[i]);
    }
    
    // Ordenar las serpientes en orden descendente de e_i
    // Si e_i es igual, ordenar por s_i descendente para minimizar x_i
    sort(snakes.begin(), snakes.end(), [&](const pair<int,int> &a, const pair<int,int> &b) -> bool{
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });
    
    // Asignar posiciones iniciales
    // x_i: posición inicial de la serpiente i
    // r_i: posición final actual de la serpiente i
    vector<ll> x(n+1, 0); // 1-based
    vector<ll> r(n+1, 0); // 1-based
    ll current_pos =1;
    for(auto &[ei, si]: snakes){
        x[si] = current_pos;
        r[si] = current_pos + ei;
        current_pos = r[si] +1;
    }
    
    // Calcular el score (máximo cell ocupado durante las operaciones)
    ll score =0;
    for(int i=1; i<=n; ++i){
        score = max(score, r[i]);
    }
    
    cout << score << "\n";
}
