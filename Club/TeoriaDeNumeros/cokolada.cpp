#include <bits/stdc++.h>

using namespace std;

int main(){

  int k;
  cin>>k;

  int bar = pow(2,ceil(log2(k)));
  int breaks = 0;
  int pieces;

  pieces = bar;
  while (k>0 && k!=bar){
    pieces /= 2;
    if (k >= pieces){
      k -= pieces;
    }
    breaks++;
  }

  cout<<bar<<" "<<breaks<<endl;

  return 0;
}
