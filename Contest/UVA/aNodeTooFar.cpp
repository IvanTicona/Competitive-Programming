#include<bits/stdc++.h>
#define int long long int

using namespace std;
map<int, vector<int>> network;
map<int, int> nivel;
map<int, bool> vis;

void bfs(int nodoInicial){
  queue<int> cola;
  cola.push(nodoInicial);
  nivel[nodoInicial] = 0;
  vis[nodoInicial]=true;
  while(!cola.empty()){
    int nodoActual=cola.front();
    cola.pop();
    for (auto vec: network[nodoActual]){
      if(!vis[vec]){
        cola.push(vec);
        nivel[vec]=nivel[nodoActual]+1;
        vis[vec]=true;
      }
    }
  }
}

int32_t main(){

  int nc;
  int _case=0;
  while (cin>>nc && nc!=0){
    network.clear();
    for (int i = 0; i < nc; i++){
      int a, b; cin>>a>>b;
      network[a].push_back(b);
      network[b].push_back(a);
    }
    int nodoInicial, ttl;
    while (cin>>nodoInicial>>ttl && !(nodoInicial==0 && ttl==0)){
      nivel.clear();
      for(auto [nodo, vec]: network){
        vis[nodo]=false;
        nivel[nodo]=1e9;
      }
      
      int nr=0;
      bfs(nodoInicial);

      for(auto [nodo, niv]: nivel){
        if(niv>ttl) nr++;
      }
      cout<<"Case "<<++_case<<": "<<nr<<" nodes not reachable from node "<<nodoInicial<<" with TTL = "<<ttl<<"."<<endl;
    }
  }

  return 0;
}