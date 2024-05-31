#include <bits/stdc++.h>

using namespace std;

int main(){

  int t, c;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    
    for (int i = 1; i <= n; i = i * 10){
      if ((n / i) % 10 != 0) c++;
    }
    cout<<c<<endl;
    c = 0;
    for (int i = 10; i <= n * 10; i = i * 10){
      if (n % i != 0) cout<<n % i<<" ";
      n -= n % i;
    }
    cout<<endl;
  }

  return 0;
}