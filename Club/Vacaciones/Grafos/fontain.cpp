#include<bits/stdc++.h>

using namespace std;

vector<string> sky;

void spreadWater(int n, int m){
  sky[n][m]='V';
  if(n==sky.size()-1) return;
  if(sky[n+1][m]=='.'){
    spreadWater(n+1,m);
  }
  if(sky[n+1][m]=='#'){
    if(m-1>=0 && sky[n][m-1]=='.') spreadWater(n,m-1);
    if(m+1<sky[n].size() && sky[n][m+1]=='.') spreadWater(n,m+1);
  }
}

int main(){
  sky.clear();
  int n, m;
  cin>>n>>m;
  for (int i = 0; i < n; i++){
    string l;
    cin>>l;
    sky.push_back(l);
  }
  cout<<endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(sky[i][j]=='V'){
        spreadWater(i,j);
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout<<sky[i]<<endl;
  }

  return 0;
}