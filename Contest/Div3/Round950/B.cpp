#include<bits/stdc++.h>

using namespace std;

#define input freopen("input.txt","r",stdin)

int main(){

  input;

  int t,n,f,k;
  cin>>t;
  while (t--){
    cin>>n>>f>>k;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin>>arr[i];
    }
    int fav = arr[f-1];
    for (int i = 0; i < n-1; i++){
      for (int j = 0; j < n-i-1; j++){
        if (arr[j] < arr[j+1]){
          int aux = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = aux;
        }
      }
    }

    if (n == k){
      cout<<"YES"<<endl;
    } else if (fav <= arr[k]){
      if (arr[k-1] == fav) cout<<"MAYBE"<<endl;
      else cout<<"NO"<<endl;
    } else if(fav > arr[k]){
      cout<<"YES"<<endl;
    }
  }

  return 0;
}