#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout);

  int n, m; cin >> n >> m;
  map<string, int> teams;

  for (int i = 1; i <= n; i++){
    teams["T"+to_string(i)] = i;
  }

  for (int q = 0; q < m; q++){
    string Ti, Tj; cin >> Ti >> Tj;
    if(teams[Ti] < teams[Tj]) continue;
    else{
      int top = teams[Tj];
      int bottom = teams[Ti];

      for (auto &[t, p]: teams){
        if( top < p && p <= bottom) p--;
      }
      teams[Tj] = bottom;
    }
  }
  map<int, string> ranking;
  for(auto &[t, p]: teams){
    ranking[p]=t;
  }

  for(auto &[p, t]: ranking){
    cout<<t<<" ";
  }  

  return 0;
}