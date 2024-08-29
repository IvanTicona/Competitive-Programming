#include<bits/stdc++.h>

using namespace std;

int main(){

  int n, k;
  cin>>n>>k;

  int km = 0;
  while(n > k){
    n -= ceil((n*1.0)/k); //Cada vez que pasamos por el mismo peaje
    km++; //paso 1
  }
  cout<<km+n+1<<endl; //siempre recorre 1km mas lo ultimo que lleva en el saco

  return 0;
}