  #include<bits/stdc++.h>

  using namespace std;

  int main(){

    int N, K; cin>>N>>K;
    int time= K-(N-1);

    cout<<(time/N)<<endl;

    return 0;
  }