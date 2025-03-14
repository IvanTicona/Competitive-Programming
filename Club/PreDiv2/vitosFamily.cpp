#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int r;
    cin>>r;
    vector<int> st(r);
    for(int i=0;i<r;i++) cin>>st[i];
    sort(st.begin(),st.end());

    int near = st[r/2];
    int mindist = 0;
    for(int v: st) mindist+=abs(near-v);
    cout<<mindist<<endl;
  }

  return 0;
}