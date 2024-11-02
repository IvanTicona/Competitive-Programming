/*
Author: Ivan Ticona
    #    # #####  #####  
    #    # #    # #    #
    #    # #    # #    #   
    #    # #####  ##### 
    #    # #      #    #
    #    # #      #    #
     ####  #      ##### 
*/
#include<bits/stdc++.h>

#define FOR(i, a, b, x) for(int i = a; i < b; i+=x)
#define FORE(i, a, b, x) for(int i = a; i <= b; i+=x)
#define FORR(i, a, b, x) for(int i = a; i >= b; i-=x)
#define SHOW(x) cout << x << endl;

using namespace std;
typedef long long ll;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;

    vector<ll> a(n+5);
    vector<ll> b(n+5);
    vector<ll> c(n+5);

    FORE(i, 1, n, 1) cin >> a[i];

    FORE(i, 2, n, 2) b[i] = max(b[i-2], a[i] - a[i-1]);

    c[n+1] = 0;

    FORR(i, n-1, 1, 2) c[i] = max(c[i+2], a[i+1] - a[i]);

    ll ans = 1e18;

    if(n%2 == 0){
      SHOW(b[n]);
      continue;
    }

    a[n+1] = 1e18+10;

    FORE(i, 1, n, 1){
      if(i%2 == 1){
        if(a[i] <= a[i-1]+1 && a[i] >= a[i+1]-1) continue;
        ans = min(ans, max(b[i-1], c[i+1]));
      }
    }

    ans = max(ans, 1LL);
    SHOW(ans);
  }

  return 0;
}