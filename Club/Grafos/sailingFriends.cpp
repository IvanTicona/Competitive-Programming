#include<bits/stdc++.h>

using namespace std;

int boats[100100];
bool haveBoat[100100];
int personHave[100100];

int groups;

int Find(int x){
  if(x==boats[x]) {
    return x;
  }
  else return boats[x]=Find(boats[x]);
}

void St(int x){
  if(x==boats[x]) {
    haveBoat[x]=true;
  }
  else St(boats[x]);
}

void Union(int a, int b){
  groups--;
  int ra = Find(a);
  int rb= Find(b);
  boats[rb] = ra;
}

int main(){

  memset(boats,0,sizeof(boats));
  memset(haveBoat,false,sizeof(haveBoat));
  int n, b, m;
  cin>>n>>b>>m;
  groups=n;
  for (int i = 1; i <= n; i++){boats[i]=i;}

  for (int i = 0; i < b; i++){
    int a;
    cin>>a;
    personHave[i] = a;
  }

  for (int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    Union(a,b);
  }

  for (int i = 0; i < b; i++){
    St(personHave[i]);
  }
  
  int aux=0, wo=0;
  for (int i = 1; i <= n; i++){
    if(haveBoat[Find(i)] && aux!=Find(i)){
      aux=Find(i);
      wo++;
    }
  }
  cout<<groups-wo<<endl;

  return 0;
}