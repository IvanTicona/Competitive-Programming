#include<bits/stdc++.h>

using namespace std;

vector<string> flood;
bool vis[25][25];

int x[]={1,-1,0,0};
int y[]={0,0,1,-1};

int biggest[6];
int colors[6];
int l;

int currentColor=0;
int toOrigen=0;

void dfs(int f, int c, int color){
  if(f<0||c<0||f>=l||c>=l) return;
  if(vis[f][c]) return;
  vis[f][c]=true;
  toOrigen++;
  for (int i = 0; i < 4; i++){
    int nf=f+x[i];
    int nc=c+y[i];
    if(nf<0||nc<0||nf>=l||nc>=l) continue;
    if(!vis[nf][nc]&&flood[nf][nc]==color){
      cout<<flood[nf][nc]<<" - ";
    //   dfs(nf,nc,color);
    }
  }
}

int main(){

  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    l=n;
    flood.clear();
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < n; i++){
      string l;
      cin>>l;
      flood.push_back(l);
    }
    currentColor = flood[0][0];
    
    dfs(0,0,3);


    // cout<<endl;
    // for (int i = 0; i < n; i++){
    //   cout<<flood[i]<<endl;
    // }
    // cout<<endl;
    // cout<<toOrigen<<endl;
  }

  return 0;
}