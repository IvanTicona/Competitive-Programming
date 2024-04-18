#include<bits/stdc++.h>

using namespace std;

int main(){
  int stations,s;
  cin>>stations>>s;
  vector<int> ida(stations);
  vector<int> vuelta(stations);
  for (int i = 0; i < stations; i++){
    cin>>ida[i];
  }
  for (int i = 0; i < stations; i++){
    cin>>vuelta[i];
  }
  if(!ida[0]) {cout<<"NO"; return 0;}
  if(ida[s-1]) {cout<<"YES"; return 0;}
  for (int i = s-1; i < stations; i++){
    if(!ida[i]&&!vuelta[i]){cout<<"NO";return 0;}
  }
  if(vuelta[s-1]){cout<<"YES"; return 0;}
  cout<<"NO";
  
  return 0;
}