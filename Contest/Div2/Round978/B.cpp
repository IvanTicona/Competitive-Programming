
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n, x; cin >> n >> x;
    // Cola de prioridad para los modelos
    int customers = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
      int a; cin >> a;
      pq.push(a);
    }

    while (!pq.empty())
    {
      int c = x;
      while(!pq.empty() && c > 0){
        int a = pq.top();
        pq.pop();
        c--;
        if( a - 1 == 0) continue;
        pq.push(a-1);
      }
      customers++;
    }

    cout << customers << endl; 
  }

  return 0;
}