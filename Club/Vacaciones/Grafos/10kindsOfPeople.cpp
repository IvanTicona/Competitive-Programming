#include<bits/stdc++.h>

using namespace std;

vector<string> mapita;
int area[1010][1010];

int lf, lc;

int f[]={0,0,1,-1};
int c[]={1,-1,0,0};

void dfs(int fa, int ca, int ar, char bin){
  if(area[fa][ca]!=0) return;
  area[fa][ca]=ar;
  for (int i = 0; i < 4; i++){
    int nf=fa+f[i];
    int nc=ca+c[i];
    if(nf<0 || nc<0 || nf>=lf || nc>=lc || mapita[nf][nc]!=bin) continue;
    dfs(nf,nc,ar,bin);
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
  int ar=1;
  memset(area,0,sizeof(area));
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if(area[i][j]==0){
        dfs(i,j,ar,mapita[i][j]);
        ar++;
      }
    }
  }
  int n;
  cin>>n;
  while (n--){
    int r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--,c1--,r2--,c2--;
    if(mapita[r1][c1]=='0' && area[r1][c1]==area[r2][c2]) cout<<"binary"<<endl;
    else if(mapita[r1][c1]=='1' && area[r1][c1]==area[r2][c2]) cout<<"decimal"<<endl;
    else cout<<"neither"<<endl;
  }

  return 0;
}