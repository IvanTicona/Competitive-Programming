#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  int t;
  cin>>t;
  while (t--){
    ll n, coins;
    cin>>n>>coins;
    vector<ll> flowers(n);
    for (ll i = 0; i < n; i++){
      cin>>flowers[i];
    }
    sort(flowers.begin(), flowers.end(), greater<ll>());

    ll maxPetals=0;
    for (int j = 0; j < n; j++){
      ll poss=coins;
      ll petals=0;
      
      ll i=j;
      ll maxi=flowers[j];
      while (petals<=poss){
        if(!(maxi-1==flowers[i] || flowers[i]==maxi+1 || flowers[i]==maxi)) break;
        if(petals+flowers[i]>poss) break;
        petals += flowers[i];
        i++;
      }
      maxPetals=max(maxPetals,petals);
    }
    cout<<maxPetals<<endl;
  }
  

  return 0;
}