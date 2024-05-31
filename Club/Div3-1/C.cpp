#include <bits/stdc++.h>

using namespace std;

int main(){

  int a, c;
  cin>>a;
  while (a--)
  {
    int b;
    cin>>b;
    
    for (int i = 1; i <= b; i = i * 10){
      if ((b / i) % 10 != 0) c++;
    }
    cout<<c<<endl;
    c = 0;
    for (int i = 10; i <= b * 10; i = i * 10){
      if (b % i != 0) cout<<b % i<<" ";
      b -= b % i;
    }
    cout<<endl;
  }

  return 0;
}