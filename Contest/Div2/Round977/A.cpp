
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--){
    int n; cin>>n;
    vector<int> arr(n);
    for(int &v: arr) cin>>v;
    priority_queue<int, vector<int>, greater<int>> cola;
    for(int &v: arr) cola.push(v);

    while(cola.size()>1){
    int a = cola.top(); cola.pop();
    int b = cola.top(); cola.pop();
      cola.push((a+b)/2);
    }
    cout<<cola.top()<<endl;
  }
  
  

  return 0;
}