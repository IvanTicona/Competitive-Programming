#include<bits/stdc++.h>

using namespace std;

int coast[1010][1010];
bool vis[1010][1010];

int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int lf,lc;
int l=0;

void compute(int f, int c){
  if(vis[f][c]) return;
  vis[f][c]=true;
  for (int i = 0; i < 4; i++){
    int nf=f+y[i];
    int nc=c+x[i];
    if(nf<0||nc<0||nf>lf+1||nc>lc+1) continue;
    if(coast[nf][nc]==1) l++;
    if(coast[nf][nc]==0) compute(nf,nc);
  }
}

int main(){

  int n, m;
  cin>>n>>m;
  lf=n,lc=m;
  memset(coast,0,sizeof(coast));
  memset(vis,false,sizeof(vis));
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      char c;
      cin>>c;
      coast[i][j]=c-'0';
    }
  }
  compute(0,0);
  cout<<l<<endl;

  return 0;
}