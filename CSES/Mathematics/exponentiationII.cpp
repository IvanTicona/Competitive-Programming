#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modulo = 1e9 + 7;

ll power(ll base, ll exponente, ll mod) {
    
    ll resultado = 1;
    base%=mod;
    while (exponente > 0) {
        if (exponente % 2 == 1) {
          resultado = (resultado * base) % mod;
        }
        base = (base * base) % mod;
        exponente /= 2;
    }
    return resultado;
}

int main() {
    int n;
    std::cin >> n;
    
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll base = a;
        ll exponente = power(b,c,modulo-1);
	cout << power(base,exponente,modulo) << endl;
    }
    
    return 0;
}
