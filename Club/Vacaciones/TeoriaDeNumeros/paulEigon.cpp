#include <bits/stdc++.h>

using namespace std;

int main(){
  int N, P, Q;
  cin>>N>>P>>Q;

  int totalRounds = P + Q;

  int group = totalRounds / N;

  if (group % 2 == 0){
    cout<<"paul"<<endl;
  }else{
    cout<<"opponent"<<endl;
  }

  return 0;
}
