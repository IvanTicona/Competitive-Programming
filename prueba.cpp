#include <bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);

  int t, i=1;
  cin>>t;
  while(i<=t){
	  vector<string> cards(52);
    for(string &c: cards) cin>>c;
    cout<<"Case "<<i++<<": "<<cards[32]<<endl;
  }

	return 0;
}