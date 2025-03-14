#include<bits/stdc++.h>

using namespace std;

vector<int> city[1010];
bool vis[1010];
vector<int> order;

void dfs(int id){
  if(vis[id]) return;
  vis[id]=true;
  for (int i = 0; i < city[id].size(); i++){
    dfs(city[id][i]);
  }
}

int main(){

  for (int i = 0; i < 1010; i++){city[i].clear();}
  order.clear();
  memset(vis,false,sizeof(vis));

  int n;
  cin>>n;
  for (int i = 0; i < n; i++){
    int id, st;
    cin>>id>>st;
    order.push_back(id);
    for (int i = 0; i < st; i++){int id2;cin>>id2;
      city[id].push_back(id2);
    }
  }
  bool np=true;
  for (int id: order){
    if(id==0) continue;
    memset(vis,false,sizeof(vis));
    dfs(id);
    if(vis[0]) continue;
    cout<<"TRAPPED "<<id<<endl;
    np=false;
  }
  memset(vis,false,sizeof(vis));
  dfs(0);
  for (int id: order){
    if(vis[id]) continue;
    cout<<"UNREACHABLE "<<id<<endl;
    np=false;
  }
  if(np) cout<<"NO PROBLEMS"<<endl;

  return 0;
}