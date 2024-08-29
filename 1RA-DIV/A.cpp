#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, k; 
  cin>>n>>k;

  int km = 0;
  while(n > k) {
    n -= ceil((n*1.0)/k);
    km++;
  }
  cout<<km+n+1<<endl;

  return 0;
}