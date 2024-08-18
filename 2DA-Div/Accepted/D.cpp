#include<bits/stdc++.h>

using namespace std;

int main(){

  string x;
  cin>>x;

  for (long long i = 0; i < x.size(); i++){
    int newDigit = 9-(x[i]-'0');
    int oldDigit = (x[i]-'0');
    int MIN = min(oldDigit,newDigit);
    if(i==0&&MIN==0) x[i]=char(max(oldDigit,newDigit)+'0');
    else if(newDigit >= 0) x[i]=char(MIN+'0');
  }

  cout<<x<<endl;
  
  return 0;
}