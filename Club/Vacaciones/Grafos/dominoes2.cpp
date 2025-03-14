#include<bits/stdc++.h>

using namespace std;

vector<int> domino[10010];
bool vis[10010];

void dfs(int z){
  if(vis[z]) return;
  vis[z]=true;
  for (int i: domino[z]){
    dfs(i);
  }
}

int main(){

  int t;
  cin>>t;
  while (t--){
    int n, m, l;
    cin>>n>>m>>l;
    int byHand=0;
    for(int i = 0; i <= n; ++i){domino[i].clear();}
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < m; i++){
      int x, y;
      cin>>x>>y;
      domino[x].push_back(y);
    }
    for (int i = 0; i < l; i++){
      int z;
      cin>>z;
      if(vis[z]) continue;
      dfs(z);
    }
    for (int i = 1; i <= n; i++){
      if(vis[i]) byHand++;
    }
    cout<<byHand<<endl;
  }

  return 0;
}