#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int N=5;
ll memo[20][1000000];
int coinValue[]={1,3,6,10,15};

ll dp(ll type, ll value){
  if(value==0) return 1;
  if((value<0)||(type==N)) return 0;
  ll &ans = memo[type][value];
  if(ans!=-1) return ans;
  return ans = dp(type+1, value)+dp(type, value-coinValue[type]);
}

int main(){

  int t;
  cin>>t;
  while (t--){
    memset(memo, -1, sizeof(memo));
    int n;
    cin>>n;
    cout<<dp(0,n)<<endl;
  }

  return 0;
}