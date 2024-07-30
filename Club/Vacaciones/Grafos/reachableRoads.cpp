#include<bits/stdc++.h>

using namespace std;

vector<int> grafo[1010];

bool vis[1010];

void dfs(int nodoRaiz){
  stack<int> pila;
  pila.push(nodoRaiz);
  while (!pila.empty()){
    int nodoActual = pila.top();
    pila.pop();
    if(vis[nodoActual]) continue;
    vis[nodoActual] = true;
    for (int i = 0; i < grafo[nodoActual].size(); i++){
      int vec = grafo[nodoActual][i];
      if(!vis[vec]){
        pila.push(vec);
      }
    }
  }
}

int main(){

  int n;
  cin>>n;
  while (n--){
    int m, r;
    cin>>m>>r;
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < m; i++){grafo[i].clear();}
    for (int i = 0; i < r; i++){
      int a, b;
      cin>>a>>b;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }
    int c=0;
    for (int i = 0; i < m; i++){
      if(!vis[i]) {
        c++;
        dfs(i);
      }
    }
    cout<<c-1<<endl;
  }
  return 0;
}