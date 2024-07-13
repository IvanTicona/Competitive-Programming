#include<bits/stdc++.h>

using namespace std;


int main(){

  int t;
  cin>>t;
  while(t--){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> circle(n);
    vector<int> s(0);
    for (int i = 0; i < n; i++){
      circle[i]=i+1;
    }
    
    while (m--){
      int r;
      char c;
      cin>>r>>c;
      int pos=x-1;

      
      // else{

      // }
    }
    for (int i = 0; i < s.size(); i++){
      cout<<s[i]<<" ";
    }
    
  }

  return 0;
}