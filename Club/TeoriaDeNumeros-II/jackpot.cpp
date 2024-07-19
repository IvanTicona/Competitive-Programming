#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll f(vector<ll> &p){
  ll per=p[0];
  for (int i = 0; i < p.size(); i++){
    ll r = gcd(per,p[i]);
    per *= p[i];
    per /= r;
    if(per>1e9){
      per=-1;
      break;
    }
  }
  return per;
}

int main(){

  int n;
  cin>>n;
  while (n--){
    int w;
    cin>>w;
    
    vector<ll> p(w);
    for (int i = 0; i < w; i++){cin>>p[i];}
    
    ll periodicity = f(p);
    periodicity==-1? cout<<"More than a billion."<<endl:cout<<periodicity<<endl;
  }

  return 0;
}