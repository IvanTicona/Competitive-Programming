#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n,m;
    cin>>n>>m;
    int need = 7*n;
    string a;
    cin>>a;
    int arr[7];
    fill(arr, arr+7, m);
    for(int i = 0; i < n; i++){
      if(arr[a[i]-65]>0) arr[a[i]-65]--;
    }
    int count=0;
    for (int i = 0; i < 7; i++){
      count+=arr[i];
    }
    cout<<count<<endl;
  }
  

  

  return 0;
}