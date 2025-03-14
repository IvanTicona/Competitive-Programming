#include<bits/stdc++.h>

using namespace std;

int main(){

  int t, n;
  cin>>t;
  while (t--){
    string s;
    cin>>n;
    cin>>s;
    if(s.size()==2){
      cout<<2<<endl;
      break;
    }

  }
  

  return 0;
}


// void solve() {
// 	string s;
// 	cin>>s;
// 	int n=s.length();
// 	long long ans=0;
// 	vector<int> cnt(n);
// 	int sum=0;
// 	for (int i=0; i<n; ++i) {
// 		if (s[i]=='(')
// 			sum+=1;
// 		else
// 			sum-=1;
// 		ans+=cnt[sum];
// 		if (sum)
// 			cnt[sum-1>>1]=0;
// 		++cnt[sum];
// 	}
// 	cout<<ans<<endl;
// }
// int main() {
// 	int t;
// 	cin>>t;
// 	while (t--)
// 		solve();
// }