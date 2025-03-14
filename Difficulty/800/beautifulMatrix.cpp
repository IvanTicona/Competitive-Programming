#include<bits/stdc++.h>

using namespace std;


int main(){
  int count=0,ic,jc,aux,matrix[5][5];

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin>>matrix[i][j];
      if(matrix[i][j]==1){
        ic=i;
        jc=j;
      }
    }
  }
  
  while (matrix[2][2]!=1)
  {
    if(ic<2){
      aux = matrix[ic+1][jc];
      matrix[ic+1][jc]=matrix[ic][jc];
      matrix[ic][jc]=aux;
      ic++;
      count++;
    } else if(ic>2){
      aux = matrix[ic-1][jc];
      matrix[ic-1][jc]=matrix[ic][jc];
      matrix[ic][jc]=aux;
      ic--;
      count++;
    }
    if(jc<2){
      aux = matrix[ic][jc+1];
      matrix[ic][jc+1]=matrix[ic][jc];
      matrix[ic][jc]=aux;
      jc++;
      count++;
    } else if(jc>2){
      aux = matrix[ic][jc-1];
      matrix[ic][jc-1]=matrix[ic][jc];
      matrix[ic][jc]=aux;
      jc--;
      count++;
    }
  }
  
  cout<<count<<endl;

  return 0;
}