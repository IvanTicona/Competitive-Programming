#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n, k;
    cin>>n>>k;
    int grid[n][n];
    memset(grid,0,sizeof(grid));
    for (int i = 0; i < n; i++){
      string line;
      cin>>line;
      for (int j = 0; j < n; j++){
        grid[i][j]=line[j]-'0';
      }
    }

    for (int i = 0; i < n; i+=k){
      for (int j = 0; j < n; j+=k){
        cout<<grid[i][j];
      }
      cout<<endl;
    }
  }

  return 0;
}