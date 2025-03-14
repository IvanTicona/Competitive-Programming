/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n, k; cin >> n >> k;
    vector<int> b(k), c(k);
    map<int, int> types;
    for (int i = 0; i < k; i++){
      cin >> b[i] >> c[i];
      types[b[i]] += c[i];
    }
    if(types.size() > n){
      priority_queue<int> q;
      for(auto type: types){
        q.push(type.second);
      }
      int mx = 0;
      while (n--)
      {
        mx += q.top();
        q.pop();
      }
      cout << mx << endl;
      
    }else{
      int mx = 0;
      for(auto type: types){
        mx += type.second;
      }
      cout << mx << endl;
    }
  }
  

  return 0;
}