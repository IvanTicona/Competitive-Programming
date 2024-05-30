#include <bits/stdc++.h>

using namespace std;

#define input freopen("input.txt", "r", stdin)

int main(){
  input;
  int t, count;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i = i * 10){
      if ((n / i) % 10 != 0) count++;
    }
    cout << count << endl;
    count = 0;
    for (int i = 10; i <= n * 10; i = i * 10){
      if (n % i != 0) cout << n % i << " ";
      n -= n % i;
    }
    cout << endl;
  }
}