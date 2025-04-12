#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll J(ll n, ll k) {
    if(n == 1) return 1;
    
    if(n % 2 == 0) {
        if(k <= n/2)
            return 2 * k;
        else
            return 2 * J(n / 2, k - n/2) - 1;
    } 
    else {
        if(k <= n / 2)
            return 2 * k;
        else if(k == (n / 2) + 1)
            return 1;
        else
            return 2 * J((n - 1) / 2, k - (n / 2) - 1) + 1;
    }
}

int main() {
    
    ll q; cin >> q;
while(q--){
    ll n, k;
    cin >> n >> k;
    cout << J(n, k) << "\n";   
}
    return 0;
}

