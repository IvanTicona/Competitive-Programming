#include <bits/stdc++.h>

using namespace std;

#define pb push_back

class UnionFind{
public:
  int parent[110000], size[110000];
  UnionFind(int n){
    for (int i = 0; i < n; i++){
      size[i] = 1;
      parent[i] = i;
    }
  }

  int findSet(int u){
    if (parent[u] != u)
      parent[u] = findSet(parent[u]);
    return parent[u];
  }

  void unionSet(int x, int y){
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX == rootY)
      return;

    if (size[rootX] > size[rootY]){
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
    }else{
      parent[rootX] = rootY;
      size[rootY] += size[rootX];
    }
  }
};

int main(){

  int t;
  cin>>t;

  while (t--){

    UnionFind UF(110000);

    int F; cin>>F;

    map<string, int> mp;
    string st1, st2;

    while(F--){
      
      cin>>st1>>st2;

      if (!mp.count(st1)) mp[st1] = mp.size();
      if (!mp.count(st2)) mp[st2] = mp.size();

      UF.unionSet(mp[st1], mp[st2]);

      cout<<UF.size[UF.findSet(mp[st1])]<<endl;
    }
  }
  return 0;
}