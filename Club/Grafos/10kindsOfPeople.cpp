#include<bits/stdc++.h>

using namespace std;

vector<string> mapita;
bool vis[1010][1010];

int lf, lc;

int f[]={0,0,1,-1};
int c[]={1,-1,0,0};

void dfs(int fa, int ca, char bin){
  vis[fa][ca]=true;
  for (int i = 0; i < 4; i++){
    int nf=fa+f[i];
    int nc=ca+c[i];
    if(nf<0 || nc<0 || nf>=lf || nc>=lc) continue;
    if(vis[nf][nc]||mapita[nf][nc]!=bin) continue;
    dfs(nf,nc,bin);
  }
}

int main(){

  int r, c;
  cin>>r>>c;
  lf=r,lc=c;
  for (int i = 0; i < r; i++){
    string l;
    cin>>l;
    mapita.push_back(l);
  }
  int n;
  cin>>n;
  while (n--){
    int r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;

    if(mapita[r1-1][c1-1]=='1'){
      memset(vis,false,sizeof(vis));
      dfs(r1-1,c1-1,'1');
      if(vis[r2-1][c2-1]){
        cout<<"decimal"<<endl;
        continue;
      }
    }else if(mapita[r1-1][c1-1]=='0'){
      memset(vis,false,sizeof(vis));
      dfs(r1-1,c1-1,'0');
      if(vis[r2-1][r2-1]){
        cout<<"binary"<<endl;
        continue;
      }
    }
    memset(vis,false,sizeof(vis));
    cout<<"neither"<<endl;
  }
  //Tratarlos como areas, y si los puntos estan en la misma area o es binary o es decimal sino neither

  return 0;
}