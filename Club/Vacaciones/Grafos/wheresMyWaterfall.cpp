#include<bits/stdc++.h>

using namespace std;

vector<string> mapita;
int fall[1010];

void waterFall(int f, int c){
  
  mapita[f][c]='~';
  if(f==mapita.size()-1) return;
  if(mapita[f+1][c]=='O'){waterFall(f+1,c);}
  if(mapita[f+1][c]=='#'||mapita[f+1][c]=='?'){
    if(c-1>=0 && mapita[f][c-1]=='O') waterFall(f,c-1);
    if(c+1<mapita[f].size() && mapita[f][c+1]=='O') waterFall(f,c+1);
  }
}

int main(){

  mapita.clear();
  memset(fall,0,sizeof(fall));
  int n, m, k;
  cin>>n>>m>>k;
  for (int i = 0; i < k; i++){
    cin>>fall[i];
  }
  for (int i = 0; i < n; i++){
    string l;
    cin>>l;
    mapita.push_back(l);
  }
  for (int i = 0; i < k; i++){
    waterFall(0,fall[i]);
  }
  for (int i = 0; i < n; i++){
    cout<<mapita[i]<<endl;
  }

  return 0;
}