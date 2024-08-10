#include<bits/stdc++.h>

using namespace std;

int sizes[] = {1,2,3};
int prices[] = {2,3,5};

// int rodCutting(int l){
//   if(l=0) return 0;
//   int sol=0;
//   for (int i = 0; i < 3; i++){
//     int t = rodCutting(l-sizes[i]);
//     sol = max(sol,t);
//   }
//   return sol;
// }

int rodCutting(int l, int i){

  if(l==0||i>=3) return 0;

  int sol = rodCutting(l,i+1);

  if(l-sizes[i]>=0){
    int res = rodCutting(l-sizes[i],i) + prices[i];
    sol = max(sol,res);
  }
  return sol;
}

int main(){

  int longitud = 5;

  cout<<rodCutting(longitud, 0)<<endl;

  return 0;
}