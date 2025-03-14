#include<bits/stdc++.h>

using namespace std;

int islands[1010];

int Find(int x){
  if(x==islands[x]) return x;
  else return islands[x]=Find(islands[x]);
}
void Union(int x , int y){
  int xRoot=Find(x);
  int yRoot=Find(y);
  islands[xRoot]=yRoot;
}

int main(){
  
  int n, m;
  cin>>n>>m;
  memset(islands,0,sizeof(islands));
  for (int i = 1; i <= n; i++){
    islands[i]=i;
  }
  for (int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    Union(a,b);
  }
  bool conn=true;
  for (int i = 1; i <= n; i++){
    if(Find(1)!=Find(i)){
      conn=false;
    }
  }
  conn?cout<<"YES"<<endl:cout<<"NO"<<endl;
  return 0;
}