/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n, k; cin >> n >> k;
    vector<int> peldanios(n);
    for(int &c: peldanios) cin >> c;
    sort(peldanios.begin(), peldanios.end());

    bool vive = true;
    for (int i = 1; i < n; i++)
    {
      if(peldanios[i] > (peldanios[i-1] + k)){
        vive = false;
        break;
      }
    }
    
    if(vive) cout << "S" << endl;
    else cout << "F" << endl;
  }
  

  return 0;
}