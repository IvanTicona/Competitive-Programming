#include<bits/stdc++.h>

using namespace std;

vector<int> friends[10010];
bool vis[10010];
int owes[10010];
int square;

void squareAcc(int f){
  if(vis[f]) return;
  vis[f]=true;
  square+=owes[f];
  for (int i = 0; i < friends[f].size(); i++){
    squareAcc(friends[f][i]);
  }
}

int main(){

  int n, m;
  cin>>n>>m;
  for (int i = 0; i < n; i++){friends[i].clear();}
  memset(vis,false,sizeof(vis));
  memset(owes,false,sizeof(owes));
  
  for (int i = 0; i < n; i++){
    int o;
    cin>>o;
    owes[i]=o;
  }
  for (int i = 0; i < m; i++){
    int x, y;
    cin>>x>>y;
    friends[x].push_back(y);
    friends[y].push_back(x);
  }
  bool poss=true;
  for (int i = 0; i < n; i++){
    if(vis[i]) continue;
    square=0;
    squareAcc(i);
    if(square!=0){
      poss=false;
      break;
    }
  }
  if(poss){
    cout<<"POSSIBLE"<<endl;
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }

  return 0;
}