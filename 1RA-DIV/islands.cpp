#include<bits/stdc++.h>

using namespace std;

vector<string> mapa;

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
int lf, lc;

void dfs(int f, int c){
  mapa[f][c] = 'W';
  for (int i = 0; i < 4; i++){
    int nf = f + y[i];
    int nc = c + x[i];
    if(nf < 0 || nc < 0 || nf >= lf || nc >= lc || mapa[nf][nc] == 'W') continue;
    dfs(nf,nc);
  }
}

int main(){

  int r, c; cin >> r >> c;
  lf = r, lc = c;
  for (int i = 0; i < r; i++){
    string l;
    cin >> l;
    mapa.push_back(l);
  }

  int islands=0;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if(mapa[i][j] == 'L'){
        islands++;
        dfs(i,j);
      }
    }
  }
  cout << islands << endl;

  return 0;
}