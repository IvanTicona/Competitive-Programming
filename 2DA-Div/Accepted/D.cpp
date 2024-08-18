#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

  string x;
  cin>>x;

  for (ll i=0; i<x.size(); i++){
    int oldDigit = x[i]-'0';
    int newDigit = 9 - oldDigit;
    if(i==0 && newDigit==0) continue;
    if(oldDigit > newDigit) x[i]=char(newDigit+'0');
  }

  cout<<x<<endl;
  
  return 0;
}