
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
      int s = p/2;
      r -= s;
      happy += s * 2;
      alone += p%2;
    }

    if(alone<=r){
      happy+=alone;
    }else{
      happy += 2 * r - alone;
    }

    cout << happy << endl;
  }
  

  return 0;
}