#include <bits/stdc++.h>
 
using namespace std;
 
void sumParity(int n, int k) {
  if (n < k || (n%2 == 1 && k%2 == 0)) {
      cout<<"NO"<<endl;
      return;
  }
  if (n >= k && (n % 2 == k % 2)) {
      cout<<"YES"<<endl;
      for (int i = 0; i < k - 1; ++i) {
          cout<<1<<" ";
      }
      cout<<(n - (k - 1))<<endl;
      return;
  }
  if (n >= 2 * k) {
      cout<<"YES"<<endl;
      for (int i = 0; i < k - 1; ++i) {
          cout<<2<<" ";
      }
      cout<<(n - 2 * (k - 1))<<endl;
      return;
  }
  cout<<"NO"<<endl;
}
 
int main() {
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin>>n>>k;
    sumParity(n, k);
  }
  return 0;
}