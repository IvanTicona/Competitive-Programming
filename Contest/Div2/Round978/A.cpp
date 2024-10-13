
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--){
    int n, r; cin >> n >> r;
    vector<int> people(n);
    for(int &p: people) cin >> p;
    int happy=0, alone=0;
    for(int &p: people){
      if(p>1){
        if(p%2==0){
          happy+=p;
        }else{
          happy+=p-1;
          alone++;
        }
        r-=p/2;
      }else{
        alone++;
      }
    }

    while (r>0){
      if(alone<=r){
        happy+=alone;
        r-=alone;
      }else{
        alone-=2;
        r--;
      }
    }

    cout << happy << endl;
  }
  

  return 0;
}