#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){

  int t, n;
  cin>>t;
  while (t--){
    ll minimo=0;
    cin>>n;
    ll a[n], b[n+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i = 0; i < n; i++){cin>>a[i];}
    for (int i = 0; i < n+1; i++){cin>>b[i];}
    for (int i = 0; i < n; i++){minimo += abs(b[i]-a[i]);}
    ll x=1e18;
    for (int i = 0; i < n; i++) {
			if( min(a[i],b[i]) <= b[n] && b[n] <= max(a[i],b[i]) ){
				x=1;
				break;
			}
		  x=min(x,min(abs(a[i]-b[n])+1,abs(b[i]-b[n])+1));
		}
		cout<<minimo+x<<endl;
  }

  return 0;
}
