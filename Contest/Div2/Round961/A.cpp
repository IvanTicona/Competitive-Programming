#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n, k;
    cin>>n>>k;
    if(k==0){
      cout<<0<<endl;
      continue;
    }
    int chips=k;
    int diagonals=1;
    chips-=n;
    if(chips<=0){cout<<diagonals<<endl;continue;}
    for (int i = n-1; i >= 1; i--){
      chips-=i;
      diagonals++;
      if(chips<=0){cout<<diagonals<<endl;break;}
      chips-=i;
      diagonals++;
      if(chips<=0){cout<<diagonals<<endl;break;}
    }
  }
  

  return 0;
}

