#include<bits/stdc++.h>

using namespace std;

int arr[55][55];
int aux[55][55];
int n;

void rotate(){
  for(int j = n-1, k = 0; j >= 0; j--, k++){
    for(int i = 0; i < n; i++){
      aux[k][i] = arr[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      arr[i][j]=aux[i][j];
    }
  }
}

bool initialState(){
  bool row = true, col = true;
  for (int i = 0; i < n-1; i++){
    if(arr[0][i] > arr[0][i+1]){
      row = false;
      break;
    }
  }
  if(row){
    for (int i = 0; i < n-1; i++){
      if(arr[i][0] > arr[i+1][0]){
        col = false;
        break;
      }
    }
  }
  
  return row&&col;
}


int main(){

  cin>>n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>arr[i][j];
    }
  }
  int count = 0;
  while (!initialState()){
    count++;
    rotate();
  }
  
  cout<<count<<endl;

  return 0;
}