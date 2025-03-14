#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// Variables globales para la parte "dada"
int n;
vector<int> a;      // a[1..n]
vector<int> preF;   // preF[i] = a1 ⊕ a2 ⊕ ... ⊕ a_i, 1-indexado.
vector<ll> preSum;  // preSum[i] = sum_{j=1}^{i} preF[j] (para i <= n)
 
// Suma de los a_i para i <= n (entrada) y para i de n+1 a 2n (calculable, pues floor(i/2) <= n)
ll SA_small;      // suma de a[1..n]
ll SA_small_2n;   // suma de a[i] para i=1..2n
 
// "constOdd" (c) para los índices > n
int c;  // c es 0 o 1
 
// --- Función getF ---
// Calcula F(x) = a1 ⊕ a2 ⊕ ... ⊕ a_x para x >= 1.
// Para x <= n se conoce; para x > n se usa la recursión:
//    Si x es impar: getF(x) = c
//    Si x es par:   getF(x) = getF(x/2) ⊕ c
int getF(ll x) {
    if(x <= n) return preF[(int)x];
    if(x & 1LL) return c;
    return getF(x/2) ^ c;
}
 
// --- Función F_sum(L, R) ---
// Devuelve la suma de f(x)=F(x) para x en [L, R] (donde para x>n, f(x) se define como arriba).
// Si x <= n usamos los valores precomputados (preF, que es 0 o 1) y preSum.
ll F_sum(ll L, ll R) {
    if(L > R) return 0;
    if(R <= n) {
        return preSum[(int)R] - (L-1 >= 1 ? preSum[(int)L-1] : 0LL);
    }
    if(L <= n) {
        return (preSum[n] - (L-1 >= 1 ? preSum[(int)L-1] : 0LL)) + F_sum(n+1, R);
    }
    // Ahora, L >= n+1.
    ll ans = 0;
    // Los impares en [L, R]: para cada x impar se tiene f(x)=c.
    ll firstOdd = (L % 2 == 1 ? L : L+1);
    if(firstOdd <= R) {
        ll cntOdd = ((R - firstOdd) / 2) + 1;
        ans += cntOdd * c;
    }
    // Los pares en [L, R]: si x es par, escriba x = 2*y, y varía en [ceil(L/2), floor(R/2)].
    ll firstEven = (L % 2 == 0 ? L : L+1);
    if(firstEven <= R) {
        ll Y_low = firstEven / 2;
        ll Y_high = R / 2;
        ll cntEven = (Y_high - Y_low + 1);
        if(c == 0) {
            // f(2*y) = f(y)
            ans += F_sum(Y_low, Y_high);
        } else {
            // si c==1, f(2*y) = 1 - f(y)
            ans += cntEven - F_sum(Y_low, Y_high);
        }
    }
    return ans;
}
 
// --- Función SA(X) ---
// Devuelve la suma de los elementos de la secuencia a en los índices 1..X.
ll SA(ll X) {
    // Si X está en la parte dada
    if(X <= n) {
        ll s = 0;
        for (int i = 1; i <= X; i++) s += a[i];
        return s;
    }
    // Si X está entre n+1 y 2n, se puede calcular directamente (porque floor(i/2) <= n)
    if(X <= 2LL * n) {
        ll s = SA_small; // suma de 1..n
        for (ll i = n+1; i <= X; i++) {
            int idx = (int)(i/2);  // floor(i/2)
            s += preF[idx];
        }
        return s;
    }
    // Si X > 2n: descomponemos en dos partes.
    // Ya conocemos SA(2n) (calculado previamente).
    ll s = SA_small_2n;
    // Para i > 2n, se agrupan en parejas: para todo y > n,
    // a_{2y} = a_{2y+1} = f(y)  (con f(y)=getF(y)).
    // Sea Y = floor(X/2). Entonces, para y en [n+1, Y] se tienen dos términos.
    ll Y = X / 2;
    ll sumPairs = 2 * F_sum(n+1, Y);
    s += sumPairs;
    // Si X es impar, queda un extra: X = 2*Y + 1, y se suma f(Y).
    if(X & 1LL) s += getF(Y);
    return s;
}
 
// --- Función principal ---
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> n >> l >> r;
        a.resize(n+1);    // 1-indexado
        preF.resize(n+1);
        preSum.resize(n+1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
 
        // Precalcular preF: para i<= n, F(i)=a1 ⊕ ... ⊕ a_i.
        preF[0] = 0;
        for (int i = 1; i <= n; i++){
            preF[i] = preF[i-1] ^ a[i];
        }
        // Precalcular preSum de f(i) para i<= n (recordemos que f(i)=F(i) en esta parte y toma valor 0 o 1).
        preSum[0] = 0;
        for (int i = 1; i <= n; i++){
            preSum[i] = preSum[i-1] + preF[i];
        }
 
        // Calcular SA_small: suma de a[i] para i=1..n.
        SA_small = 0;
        for (int i = 1; i <= n; i++){
            SA_small += a[i];
        }
 
        // Calcular SA_small_2n: suma de a[i] para i=1..2n.
        SA_small_2n = SA_small;
        for (ll i = n+1; i <= 2LL*n; i++){
            int idx = (int)(i/2); // floor(i/2) ≤ n
            SA_small_2n += preF[idx];
        }
 
        // Calcular la constante c = constOdd.
        // Sea m0 = n+1 si n+1 es impar, o m0 = n+2 si n+1 es par.
        ll m0;
        if((n+1) & 1LL) m0 = n+1;
        else m0 = n+2;
        int Fm0; // F(m0)
        if(m0 <= n) {
            Fm0 = preF[(int)m0];
        } else {
            // m0 está entre n+1 y n+2, así que se puede calcular de forma “directa”
            if(m0 == n+1) {
                // F(n+1) = F(n) ⊕ F(floor((n+1)/2))
                int idx = (n+1)/2;
                Fm0 = preF[n] ^ preF[idx];
            } else { // m0 == n+2
                // F(n+2) = F(n+1) ⊕ F((n+2)/2)
                int idx = (n+2)/2; // note: si n es impar, (n+2)/2 = (n+1)/2.
                int F_n1 = preF[n] ^ preF[(n+1)/2];
                Fm0 = F_n1 ^ preF[idx];
            }
        }
        c = Fm0;
 
        // La respuesta es: suma de a[i] para i=l..r = SA(r) - SA(l-1)
        ll ans = SA(r) - (l > 1 ? SA(l-1) : 0);
        cout << ans << "\n";
    }
    return 0;
}
