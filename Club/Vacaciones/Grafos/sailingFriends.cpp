#include<bits/stdc++.h>

using namespace std;


int people[100100];
bool hasBoat[100100];
bool hasFriend[100100];

void makePeople(int n){
  memset(people, 0, sizeof(people));
  for (int i = 0; i < n; i++){
    people[i] = i;
  }
}

int Find(int x){
  if(x == people[x]) return x;
  else return people[x] = Find(people[x]);
}

void Union(int x, int y){
  int rx = Find(x);
  int ry = Find(y);
  people[rx] = ry;
}

int main(){

  int n, b, m;
  cin>>n>>b>>m;
  makePeople(n);
  memset(hasBoat, false, sizeof(hasBoat));
  memset(hasFriend, false, sizeof(hasFriend));
  for (int i = 0; i < b; i++){
    int a;
    cin>>a;
    hasBoat[a-1] = true;
  }
  for (int i = 0; i < m; i++){
    int x, y;
    cin>>x>>y;
    Union(x-1,y-1);
  }
  //si un amigo tiene bote entonces su representativo tambien tiene bote
  for (int i = 0; i < n; i++){
    int r = Find(i);
    if(hasBoat[i]){
      hasFriend[r]=true;
    }
  }
  int need=0;
  //si tu representativo no tiene bote, le compras 1
  // y sumas a la cuenta de los que necesitaban
  for (int i = 0; i < n; i++){
    int r = Find(i);
    if(!hasFriend[r]){
      need++;
      hasFriend[r]=true;
    }
  }
  cout<<need<<endl;

  return 0;
}