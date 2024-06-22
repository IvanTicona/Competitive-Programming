#include<bits/stdc++.h>

using namespace std;

int main(){

  int mat[10][10];
  for(int i=0;i<10;i++){mat[i][0]=1;mat[0][i]=1;}
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      mat[i][j]=mat[i-1][j]+mat[i][j-1];
    }
  }
  int n;
  cin>>n;
  cout<<mat[n-1][n-1]<<endl;

  return 0;
}