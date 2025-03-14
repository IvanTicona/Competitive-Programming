#include<bits/stdc++.h>

using namespace std;

vector<string> mapa;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};

int lf, lc;

void cleanBridges(int f, int c){
  mapa[f][c]='I';
  for (int i = 0; i < 4; i++){
    int nf=f+y[i];
    int nc=c+x[i];
    if(nf<0||nc<0||nf>=lf||nc>=lc) continue;
    if(mapa[nf][nc]=='B') cleanBridges(nf,nc);
  }
}

void countIslands(int f, int c){
  mapa[f][c]='I';
  for (int i = 0; i < 4; i++){
    int nf=f+y[i];
    int nc=c+x[i];
    if(nf<0||nc<0||nf>=lf||nc>=lc) continue;
    if(mapa[nf][nc]=='#') countIslands(nf,nc);
  }
}

void countBuses(int f, int c){
  mapa[f][c]='.';
  for (int i = 0; i < 4; i++){
    int nf=f+y[i];
    int nc=c+x[i];
    if(nf<0||nc<0||nf>=lf||nc>=lc) continue;
    if(mapa[nf][nc]=='I') countBuses(nf,nc);
  }
}

int main(){

  int f,c;
  cin>>f>>c;
  lf=f,lc=c;

  // ===== LLENAR MAPA =========
  for (int i = 0; i < f; i++){
    string l;cin>>l;
    mapa.push_back(l);
  }
  // ===========================

  // ======== BORRAR X =========
  for (int i = 0; i < f; i++){
    for (int j = 0; j < c; j++){
      if(mapa[i][j]=='X') mapa[i][j]='#';
    }
  }
  // ===========================

  // ====== CONTAR ISLAS =======
  int islands=0;
  for (int i = 0; i < f; i++){
    for (int j = 0; j < c; j++){
      if(mapa[i][j]=='#') {
        islands++;
        countIslands(i,j);
      }
    }
  }
  // ===========================

  // ===== CONTAR PUENTES ======
  int bridges=0;
  for (int i = 0; i < f; i++){
    for (int j = 0; j < c; j++){
      if(mapa[i][j]=='B'){
        bridges++;
        cleanBridges(i,j);
      }
    }
  }
  // ===========================
  
  // ====== CONTAR BUSES =======
  int needed=0;
  for (int i = 0; i < f; i++){
    for (int j = 0; j < c; j++){
      if(mapa[i][j]=='I') {
        needed++;
        countBuses(i,j);
      }
    }
  }
  // ===========================

  // cout<<"Mapa: "<<endl;
  // for (int i = 0; i < f; i++){
  //   cout<<mapa[i]<<endl;
  // }
  
  cout<<"Map "<<1<<endl;
  cout<<"islands: "<<islands<<endl;
  cout<<"bridges: "<<bridges<<endl;
  cout<<"buses needed: "<<needed<<endl;

  return 0;
}