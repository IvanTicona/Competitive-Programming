#include<bits/stdc++.h>

using namespace std;

int main(){

  int n, m;
  cin>>n>>m;
  int mapa[n][m];
  bool rice[n][m];
  memset(mapa,0,sizeof(mapa));
  memset(rice,false,sizeof(rice));
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin>>mapa[n][m];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(mapa[i][j]==0) rice[i][j]=true;
      else if(max(max(mapa[i+1][j],mapa[i-1][j]),max(mapa[i][j+1],mapa[i][j-1]))>=mapa[i][j]){

      }
    }
  }
  

  return 0;
}