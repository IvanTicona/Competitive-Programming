#include <bits/stdc++.h>

using namespace std;

int main(){

  int X;
  cin>>X;

  int count = 1;
  int factor = 2;

  while (factor * factor <= X){
    if (X % factor == 0){
      X /= factor;
      count++;
    }
    else
      factor++;
  }
  cout<<count;
  
  return 0;
}
