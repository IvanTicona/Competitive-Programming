#include <bits/stdc++.h>
using namespace std;

// Factoriza k en primos con sus exponentes
static vector<pair<long long,int>> factorize(long long n) {
    vector<pair<long long,int>> res;
    for (long long i=2; i*i<=n; i++) {
        int c=0;
        while(n%i==0) {
            n/=i; c++;
        }
        if(c>0) res.push_back({i,c});
    }
    if(n>1) res.push_back({n,1});
    return res;
}

// gcd de un vector
int gcd_all(const vector<int> &arr) {
    int g=0;
    for (auto x: arr) g = std::gcd(g,x);
    return g;
}

// Cuenta múltiplos de d en [L,R]
long long count_multiples(long long L, long long R, long long d) {
    if (d==0) return 0;
    return (R/d)-((L-1)/d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        long long k, l1,r1,l2,r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        // Factorizar k
        vector<pair<long long,int>> f = factorize(k);
        vector<int> exps;
        for (auto &pr: f) exps.push_back(pr.second);

        // Si k≥2, siempre hay al menos un factor
        int h = gcd_all(exps);

        // Encontrar w = k^(1/h)
        // Para esto, k = w^h => w = la h-ésima raíz entera de k
        // h divide todos los exponentes, así que w será un entero <= 10^9
        // Hallamos w:
        // Ya que k = ∏ p_i^{a_i}, entonces w = ∏ p_i^{a_i/h}.
        long long w=1;
        for (auto &pr : f) {
            long long p = pr.first;
            int e = pr.second / h; 
            // Elevar w: w *= p^e
            for (int i=0; i<e; i++) {
                w = w*p; 
            }
        }

        long long ans=0;
        // Generar potencias w^m
        // w^0 = 1
        // Detener cuando w^m > r2
        long long val=1;
        for (int m=0;; m++) {
            if (m>0) {
                if (val>r2/w) break;
                val = val*w;
            } else {
                val=1;
            }
            if (val<l2) continue;
            if (val>r2) break;

            // h' = h/gcd(h,m)
            int g = std::gcd(h,m);
            int hprime = h/g;

            // Contar x en [l1,r1] múltiplos de hprime
            long long cnt = count_multiples(l1,r1,hprime);
            ans += cnt;
        }

        cout << ans << "\n";
    }

    return 0;
}
