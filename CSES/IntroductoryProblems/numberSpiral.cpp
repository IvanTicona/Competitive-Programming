#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x;
        ll n = max(y, x);
        ll n_sq = n * n;
        ll prev_sq = (n-1) * (n-1);
        ll number;
        if(n %2 ==0){
            if(y ==n){
                number = n_sq - x +1;
            }
            else{
                number = prev_sq + y;
            }
        }
        else{
            if(x ==n){
                number = n_sq - y +1;
            }
            else{
                number = prev_sq + x;
            }
        }
        cout << number << "\n";
    }
}
