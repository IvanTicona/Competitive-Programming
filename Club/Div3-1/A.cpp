#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){

  int t;
  cin>>t;
  while (t--){

    lli n, k;
    cin>>n>>k;
    lli div = k/(n-1);
    lli ex = k%(n-1);
    lli kth = ex + div*n;
    if(ex == 0) kth--;
    cout<<kth<<endl;
    
  }

  return 0;
}