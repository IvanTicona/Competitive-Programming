#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  double f = 0;
  for (int i = 0; i < n; i++){
    double x;
    cin>>x;
    f += x;
  }
  cout<<fixed<<setprecision(12)<<f/n<<endl;

  return 0;
}