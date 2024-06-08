#include<bits/stdc++.h>

using namespace std;

int main() {

  int n, m, a;
  cin>>n>>m>>a;
  long long r = ceil(static_cast<double>(n) / a)*ceil(static_cast<double>(m) / a);
  cout<<r<<endl;
  return 0;
}
