#include<bits/stdc++.h>

using namespace std;

int num[200010];

void solve(){

	int n,x,k; cin>>n>>x;

	for(int i = 0; i < n; i++) num[i]=0;
	
  for(int i = 1; i <= n; i++){
		cin>>k;
		if(k<n) num[k]++;
	}

	for(int i = 0; i < n; i++){
		if(!num[i]){
			cout << i << endl;
			return;
		}
		if(i+x < n) num[i + x] += num[i]-1;
	}
	cout<<n<<endl;
}

int main(){

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while(t--){
		solve();
	}

  return 0;
}