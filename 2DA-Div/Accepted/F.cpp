#include<bits/stdc++.h>

using namespace std;

int grid[1010][1010];
bool vis[1010][1010];

int lf;
int lc;

int f[]={0,0,1,-1};
int c[]={1,-1,0,0};

void dfs(int i, int j, int &vol){
  if(grid[i][j]==0) return;
  vis[i][j]=true;
  vol+=grid[i][j];
  for (int d = 0; d < 4; d++){
    int ni = i+f[d];
    int nj = j+c[d];
    if(ni<0||nj<0||ni>=lf||nj>=lc||grid[ni][nj]==0) continue;
    if(!vis[ni][nj]) dfs(ni, nj, vol);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while (t--){
    memset(grid,0,sizeof(grid));
    memset(vis,false,sizeof(vis));
    int n, m;
    cin>>n>>m;
    lf=n;
    lc=m;
    int result=0;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin>>grid[i][j];
      }
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if(grid[i][j]!=0&&!vis[i][j]){
          int vol=0;
          dfs(i,j,vol);
          result=max(result,vol);
        }
      }
    }
    cout<<result<<endl;
  }

  return 0;
}