#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
// Función para calcular la potencia modular.
long long modExp(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
// Inversa modular (MOD es primo).
long long invMod(long long a) {
    return modExp(a, MOD-2);
}
 
// Para simplificar, usamos typedefs.
typedef long long ll;
 
// Se supone que los índices de vértices son de 1 a n.
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        // Caso trivial: si n==1, no hay par de hojas.
        if(n == 1){
            int p, q;
            cin >> p >> q;
            // Se leen las aristas (no hay).
            cout << 0 << "\n";
            continue;
        }
 
        vector<ll> s(n+1); // s[i] = probabilidad de sobrevivir de i.
        // Leemos las probabilidades (p_i, q_i) y calculamos s[i]=(q-p)/q mod MOD.
        for (int i = 1; i <= n; i++){
            int p, q;
            cin >> p >> q;
            ll num = (q - p) % MOD;
            if(num < 0) num += MOD;
            ll den = q % MOD;
            s[i] = (num * invMod(den)) % MOD;
        }
 
        // Leemos el árbol.
        vector<vector<int>> adj(n+1);
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        // Precalcular para cada vértice i: P(i)=∏_{w in adj[i]}(1-s[w])
        vector<ll> P(n+1, 1);
        for (int i = 1; i <= n; i++){
            for (int w : adj[i]){
                ll term = (1 - s[w]) % MOD;
                if(term < 0) term += MOD;
                P[i] = (P[i] * term) % MOD;
            }
        }
 
        // Calcular L(i) = sum_{x in adj[i]} A(i,x), donde A(i,x)= s[i]*s[x]*(P(i) * inv(1-s[x])).
        vector<ll> L(n+1, 0);
        for (int i = 1; i <= n; i++){
            ll sumVal = 0;
            for (int x : adj[i]){
                ll invTerm = invMod((1 - s[x] + MOD) % MOD);
                ll A = s[i] * s[x] % MOD;
                A = A * P[i] % MOD;
                A = A * invTerm % MOD;
                sumVal = (sumVal + A) % MOD;
            }
            L[i] = sumVal;
        }
 
        // S_total = 1/2*((sum_i L(i))^2 - sum_i L(i)^2)
        ll S = 0;
        ll sumSq = 0;
        for (int i = 1; i <= n; i++){
            S = (S + L[i]) % MOD;
            sumSq = (sumSq + (L[i]*L[i]) % MOD) % MOD;
        }
        ll half = invMod(2);
        ll S_total = (( (S * S) % MOD - sumSq ) % MOD + MOD) % MOD;
        S_total = S_total * half % MOD;
 
        // Corrección para pares de vértices adyacentes.
        ll Corr_adj = 0;
        // Cada arista se procesa una vez.
        vector<bool> used(n+1, false);
        for (int u = 1; u <= n; u++){
            for (int v : adj[u]){
                if(u < v){
                    // Para la arista (u,v):
                    // J(u,v)= s[u]*s[v]* ( (P(u)/ (1-s[v]))*(P(v)/(1-s[u])) )
                    ll inv1 = invMod((1 - s[v] + MOD) % MOD);
                    ll inv2 = invMod((1 - s[u] + MOD) % MOD);
                    ll Juv = s[u] * s[v] % MOD;
                    Juv = Juv * P[u] % MOD;
                    Juv = Juv * inv1 % MOD;
                    Juv = Juv * P[v] % MOD;
                    Juv = Juv * inv2 % MOD;
                    ll prod = (L[u] * L[v]) % MOD;
                    ll diff = (Juv - prod + MOD) % MOD;
                    Corr_adj = (Corr_adj + diff) % MOD;
                }
            }
        }
 
        // Corrección para pares a distancia 2.
        ll Corr_d2 = 0;
        // Para cada vértice x, se consideran todos los pares u,v en adj[x].
        for (int x = 1; x <= n; x++){
            int d = adj[x].size();
            if(d < 2) continue;
            ll sumA = 0, sumA2 = 0;
            ll sumL = 0, sumL2 = 0;
            for (int u : adj[x]){
                // A(u,x)= s[u]*s[x]*(P(u)*inv(1-s[x]))
                ll invTerm = invMod((1 - s[x] + MOD) % MOD);
                ll A = s[u] * s[x] % MOD;
                A = A * P[u] % MOD;
                A = A * invTerm % MOD;
                sumA = (sumA + A) % MOD;
                sumA2 = (sumA2 + A * A % MOD) % MOD;
 
                sumL = (sumL + L[u]) % MOD;
                sumL2 = (sumL2 + L[u]*L[u] % MOD) % MOD;
            }
            // Suma sobre pares: (sumA^2 - sumA2)/2, y luego dividir por s[x] (pues en J(u,v) aparece un factor s[x] de menos)
            ll Jd2 = ( ( ( (sumA * sumA) % MOD - sumA2 + MOD) % MOD ) * half ) % MOD;
            Jd2 = Jd2 * invMod(s[x]) % MOD; // pues J(u,v)= (A(u,x)*A(v,x))/s[x]
 
            ll Indep = (((sumL * sumL) % MOD - sumL2 + MOD) % MOD) * half % MOD;
 
            ll diff = (Jd2 - Indep + MOD) % MOD;
            Corr_d2 = (Corr_d2 + diff) % MOD;
        }
 
        ll ans = (S_total + Corr_adj + Corr_d2) % MOD;
        cout << ans % MOD << "\n";
    }
    return 0;
}
