#include<bits/stdc++.h>

using namespace std;

vector<string> tiles;
int colors[10];

int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int largestPath[6];
int currentColor;

void dfs(int f, int c){
  if(f<0 || f>=tiles.size() || c<0 || c>=tiles[f].size()) return;
  

}

int main(){

  int t;
  cin>>t;
  while (t--){
    memset(colors,0,sizeof(colors));
    tiles.clear();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
      string l;
      cin>>l;
      tiles.push_back(l);
    }
    currentColor=tiles[0][0];
    int moves=0;
    dfs(0,0);

    cout<<moves<<endl;
    cout<<colors[0];
    for (int i = 1; i < 7; i++){
      cout<<" "<<colors[i];
    }
    cout<<endl;
  }

  return 0;
}