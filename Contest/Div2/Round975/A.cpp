#include<bits/stdc++.h>

using namespace std;

long long INF = 1000000000010;

int main(){

  freopen("input.txt","r",stdin);

  int t; cin>>t;

  while (t--){
    int n; cin>>n;
    vector<long long> arr(n);
    for(long long &v: arr) cin>>v;
    if(n%2==0){
      long long m=0, mp=0, mi=0;
      for (long long i = 0; i < n; i++){

      }
      m+=(n/2);
      cout<<m<<endl;
    }else{
      long long mp=0, mi=0, np=0, ni=0;
      for(long long i=0; i<n; i++){
        if(i%2==0){
          mp=max(mp,arr[i]);
          if(i==0) np=min(INF, arr[i]);
          else np=min(np,arr[i]);
        }else{
          mi=max(mi,arr[i]);
          if(i==1) ni=min(INF, arr[i]);
          else ni=min(ni,arr[i]);
        }
      }
      long long cp=0, ci=0;
      for(long long i=0; i<n; i++){
        if(i%2==0) cp++; 
        else ci++;
      }
      cout<<max(mp+np+cp,mi+ni+ci)<<endl;
    }
  }

  return 0;
}