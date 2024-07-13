#include<bits/stdc++.h>

using namespace std;

int main(){

  int col;
  cin>>col;
  int arr[col];
  for (int i = 0; i < col; i++){
    cin>>arr[i];
  }
  for (int i = 0; i < col-1; i++){
    for (int j = 0; j < col-i-1; j++){
      if(arr[j]>arr[j+1]){
        int aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
      }
    }
  }
  for (int i = 0; i < col; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}