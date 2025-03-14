#include<bits/stdc++.h>

using namespace std;

vector<string> petri;

int x[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int y[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m;
int counter=0;

void countAmebas(int a, int b){
  petri[a][b] = '.';
  for (int i = 0; i < 8; i++){
    int nx = a+x[i];
    int ny = b+y[i];
    if(nx>=0 && nx<n && ny>=0 && ny<m && petri[nx][ny]=='#' ){
      countAmebas(nx,ny);
    }
  }
}

int main(){

  cin>>n>>m;
  for (int i = 0; i < n; i++){
    string line;
    cin>>line;
    petri.push_back(line);
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(petri[i][j]=='#'){
        counter++;
        countAmebas(i,j);
      }
    }
  }
  cout<<counter<<endl;

  return 0;
}