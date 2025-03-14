/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

bool place[8][8];

void checkPlaces(int h, int k){

  for (int i = 0; i < 8; i++)
  {
    place[h][i] = true;
    place[i][k] = true;
  }
  
}

int countEmptys(){
  int cnt = 0;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if(place[i][j] == false) cnt++;
    }
  }

  return cnt;
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  memset(place, false, sizeof(place));

  vector<string> m(8);
  for(string &s: m) cin >> s;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if(m[i][j] == '#'){
        checkPlaces(i,j);
      }
    }
  }
  
  cout << countEmptys() << endl;

  return 0;
}