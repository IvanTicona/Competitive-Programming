#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll doodle(ll n, ll m){
  ll a = (n - 1) / gcd(n - 1, m - 1);
  ll b = (m - 1) / gcd(n - 1, m - 1);

  ll term1 = b * (n - 1);
  ll term2 = 1;
  ll term3 = (a - 1) * (b - 1) / 2;
  ll correction = term1 + term2 - term3;

  ll filled = n * m - correction;
  return filled;
}

int main(){

  int n;
  cin>>n;
  while (n--){
    int x, y;
    cin>>x>>y;
    cout<<x*y-doodle(x,y)<<endl;
  }
  

  return 0;
}