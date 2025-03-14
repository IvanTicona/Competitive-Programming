#include<bits/stdc++.h>

using namespace std;

int main(){

  long long t;
  cin>>t;
  while (t--){
    long long n, m;
    cin>>n>>m;
    long long a[n+3][m+3];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        cin>>a[i][j];
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        if(a[i][j] > a[i+1][j] && 
              a[i][j] > a[i-1][j] && 
              a[i][j] > a[i][j+1] && 
              a[i][j] > a[i][j-1] ){
          a[i][j]=max(max(a[i+1][j], a[i-1][j]), max(a[i][j+1], a[i][j-1]));
        }
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}