#include<bits/stdc++.h>

using namespace std;

vector<string> sky;

int x[]={1,-1,0,0};
int y[]={0,0,-1,1};

void countStars(int xx, int yy, int row, int col){
  sky[xx][yy]='#';
  for (int i = 0; i < 4; i++){
    int nx=xx+x[i]; 
    int ny=yy+y[i];
    if(nx>=0 && nx<row && ny>=0 && ny<col && sky[nx][ny]=='-'){
      countStars(nx,ny,row,col);
    }
  }
}

int main(){
  int m,n,c=1;
  while (cin>>m>>n){
    sky.clear();
    int stars=0;
    for (int i = 0; i < m; i++){
      string l;
      cin>>l;
      sky.push_back(l);
    }
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if(sky[i][j]=='-'){
          stars++;
          countStars(i,j,m,n);
        } 
      }
    }
    cout<<"Case "<<c++<<": "<<stars<<endl;
  }

  return 0;
}