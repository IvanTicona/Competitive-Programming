#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int need=40;

int hotdogs[] = {10, 10, 10, 10};
int buns[] = {8, 8, 8, 12, 12, 8, 12, 8, 12, 12 }; //size = 10
int INF = 1e9;

void showComb(int i, int count, int result, int objs){
  if(count+buns[i]>need||i>=10) return;
  r=
  showComb(i+1, count, min(result, objs), objs+1);
}

int main(){

  int packs=0;
  showComb(0, 0, INF, 0);

  return 0;
}