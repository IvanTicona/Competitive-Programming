#include<bits/stdc++.h>

using namespace std;

int main(){

  string S, T;

  cin>>S>>T;

  int c=0;
  for (int i = 0; i < T.size(); i++){
    if(c == 0 && S[c] == T[i]){
      cout<<(i+1);
      c++;
    }
    else if(c>0 && S[c] == T[i]){
      cout<<" "<<(i+1);
      c++;
    }
  }

  return 0;
}