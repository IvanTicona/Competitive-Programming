#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  int arr[n];
  int sum=0;
  for (int i = 0; i < n; i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  
  for(int i = 0; i < n-1; i++) {     
    for (int j = 0; j < n-i-1; j++) { 
      if (arr[j] < arr[j+1]) {
        int aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
      }
    }
  }
  
  int me=0,coins=0;
  for (int i = 0; i < n; i++){
    coins++;
    me+=arr[i];
    sum-=arr[i];
    if(me>sum){
      break;
    }
  }
  cout<<coins<<endl;

  return 0;
}