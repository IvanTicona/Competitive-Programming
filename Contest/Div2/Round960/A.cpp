#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int t;
  cin>>t;

  while (t--) {
    int n, mx=0;
    cin>>n;

    vector<int> a(n,0);
    for (int i = 0; i < n; ++i) {
      cin>>a[i];
    }

    int turn=0;
    while (true) {
      bool moved = false;
      for (int i = 0; i < n; ++i) {
        if (a[i] >= mx) {
          mx = a[i];
          a[i] = 0;
          moved = true;
          break;  // Solo una movida por turno
        }
      }
      if (!moved) break; // Si no se hizo ningún movimiento, se termina el juego
      turn++;
    }
    
    if(turn%2==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

  return 0;
}
