#include<bits/stdc++.h>

using namespace std;

vector<string> mapa;
int w, h;
int goldCoins=0;

int x[]={1,-1,0,0};
int y[]={0,0,-1,1};

void getCoins(int xx, int yy){
  mapa[xx][yy]='x';
  if(mapa[xx+1][yy]=='T'||mapa[xx-1][yy]=='T'||mapa[xx][yy+1]=='T'||mapa[xx][yy-1]=='T') return;
  for (int i = 0; i < 4; i++){
    int nx=xx+x[i];
    int ny=yy+y[i];
    if(mapa[nx][ny]=='#') continue;
    if(nx>=0 && nx<h && ny>=0 && ny<w && (mapa[nx][ny]=='.'||mapa[nx][ny]=='G')){
      if(mapa[nx][ny]=='G') goldCoins++;
      getCoins(nx,ny);
    }
  }
}

int main(){

  cin>>w>>h;
  for (int i = 0; i < h; i++){
    string l;
    cin>>l;
    mapa.push_back(l);
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if(mapa[i][j]=='P'){
        getCoins(i,j);
      }
    }
  }
  cout<<goldCoins<<endl;

  return 0;
}