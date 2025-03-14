#include<bits/stdc++.h>

using namespace std;

// ceil(7/2) //División entera
// double(7)/2 //División real
// ceil(double(7)/2) //División redondeo hacia arriba
// static_cast<tipo>(variable) //Cast más seguro

int main() {

  int n, m, a;
  cin>>n>>m>>a;
  long long r = ceil(static_cast<double>(n) / a)*ceil(static_cast<double>(m) / a);
  cout<<r<<endl;
  return 0;
}
