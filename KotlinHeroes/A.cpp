#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin>>arr[i];
    }
    for (int i = 0; i < n-2; i++){
      if(arr[i]!=arr[i+1]){
        if(arr[i+1]!=arr[i+2]){
          cout<<i+2<<endl;
          break;
        }else{
          cout<<i+1<<endl;
          break;
        }
      }else if(arr[i]!=arr[i+2]){
        cout<<i+3<<endl;
        break;
      }
    }
  }

  return 0;
}