# Algoritmos de ordenamiento Topologico

```
#include<bits/stdc++.h>

using namespace std;

vector<int> grafo[1000];
int degree[1000];
bool vis[1000];
vector<int> ts;

void topsort(int n){
  vis[n]=true;
  for (int vec: grafo[n]){
    if(!vis[vec]) topsort(vec);
  }
  ts.push_back(n);
}


int main(){

  int n, m, x, y;
  cin>>n>>m>>x>>y;
  
  for (int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    grafo[b].push_back(a);
    degree[a]++;
  }
  cout<<"Grado: "<<endl;
  for (int i = 1; i <= n; i++){
    cout<<degree[i]<<" ";
  }
  cout<<endl;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++){
    if(degree[i]==0) pq.push(i);
  }
  cout<<"Kahn: "<<endl;
  while (!pq.empty()){
    int nodoActual=pq.top(); pq.pop();
    cout<<nodoActual<<" ";
    for(int vec: grafo[nodoActual]){
      --degree[vec];
      if(degree[vec]>0) continue;
      pq.push(vec);
    }
  }
  // cout<<endl;
  // for (int i = 1; i <= n; i++){
  //   cout<<degree[i]<<" ";
  // }
  cout<<endl<<"TopoSort:"<<endl;
  for (int i = 1; i <= n; i++){
    if(!vis[i]) topsort(i);
  }
  
  reverse(ts.begin(),ts.end());
  for (int n: ts){
    cout<<n<<" ";
  }

  return 0;
}
```