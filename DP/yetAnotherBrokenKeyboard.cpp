/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int arr[200010];
bool valid[200010];

// void bottomUp(int n){
//   memset(arr, 0, sizeof(arr));
//   for (int i = 1; i <= n; i++)
//   {
//     if(valid[i]){
//       arr[i] = arr[i-1] + 1;
//     }
//   }
// }
int limit;

long long topDown(int i, long long suma, long long acumulador){
  if(i == limit) return suma;
  return topDown(i + 1, suma + (valid[i]? acumulador+1 : 0), (valid[i]? acumulador + 1 : 0));
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, k; cin >> n >> k;
  limit = n;
  // string s1, s="-"; cin >> s1;
  string s; cin >> s;
  // s+=s1;
  memset(valid, false, sizeof(valid));

  for (int i = 0; i < k; i++)
  {
    char c; cin >> c;
    for (int j = 0; j < n; j++)
    {
      if(c == s[j]) valid[j] = true;
    }
  }
  // bottomUp(n);
  // for(int i = 1; i <= n; i++) cout << arr[i] << " ";

  // long long sum = 0;
  // for(int i = 1; i <= n; i++) sum += arr[i];
  cout << topDown(0, 0, 0) << endl;

  return 0;
}