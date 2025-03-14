#include<bits/stdc++.h>

using namespace std;

int main(){

  int t; 
  cin>>t;
  while (t--){
    vector<string> mb;
    int n; cin>>n;
    for (int i = 0; i < n; i++){
      string l; cin>>l;
      mb.push_back(l);
    }
    for (int i = n-1; i >= 0; i--){
      for (int j = 3; j >= 0; j--){
        if(mb[i][j]=='#'){
          cout<<j+1<<" ";
        }
      }
    }
    cout<<endl;
  }

  return 0;
}