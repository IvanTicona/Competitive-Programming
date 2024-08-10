#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef vector<ui> vi;

ui calcHigh(ui i, ui j, ui k){
  return min(j-i,j-k);
}

int main(){

  ui N;
  cin>>N;
  vi heights(N);
  for (ui i = 0; i < N; i++){
    cin>>heights[i];
  }
  for(ui i=1; i<N-1; i++){
    for(ui j=0; j<N; j++){
      for(ui h=0; h<N; h++){

      }
    }
  }

  return 0;
}