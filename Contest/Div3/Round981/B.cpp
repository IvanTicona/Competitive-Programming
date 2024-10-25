/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int montains[510][510];

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
  {
    memset(montains, 0, sizeof(montains));
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> montains[i][j];
      }
      
    }

    for (int k = n-1; k >= 0; k--)
    {
      int i = k;
      int j = 0;
      int aux = 0;
      while(i >= 0 && j >= 0 && i < n && j < n){
        if(montains[i][j] < 0){
          aux = max(aux, abs(montains[i][j]));
        }
        i++;
        j++;
      }
      cnt += aux;
    }
    for (int k = 1; k < n; k++)
    {
      int i = 0;
      int j = k;
      int aux = 0;
      while(i >= 0 && j >= 0 && i < n && j < n){
        if(montains[i][j] < 0){
          aux = max(aux, abs(montains[i][j]));
        }
        i++;
        j++;
      }
      cnt += aux;
    }

    cout << cnt << endl;
  }

  return 0;
}